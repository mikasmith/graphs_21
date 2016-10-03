/*graph.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "graph.h"
#include "queue.h"

#define IS_UNVISITED(x) (UNVISITED == (x)->state)
#define IS_VISITED_SELF(x) (VISITED_SELF == (x)->state)
#define IS_VISITED_DESCENDANTS(x) (VISITED_DESCENDANTS == (x)->state)


typedef struct vertex *vertex;
typedef enum { UNVISITED, VISITED_SELF, VISITED_DESCENDANTS } vertex_state;

struct vertex{
    int predecessor;
    int distance;
    vertex_state state;
    int finish;
};

struct graphrec{
    int **edges;
    vertex *vertices;
    int num_vertex;
};

graph graph_new(int num_vertex){
    int i;
    int j;
    graph result = emalloc(sizeof *result);
    result->num_vertex = num_vertex;
    result->vertices = emalloc(num_vertex * sizeof result->vertices[0]);
    result->edges = emalloc(num_vertex * sizeof result->edges[0]);
    for(i=0; i<num_vertex;i++){
        /*not sure how to initialise an empty array of arrays */
        result->edges[i] = emalloc(num_vertex * sizeof result->edges[i][0]);
        for(j=0; j<num_vertex; j++){
            result->edges[i][j] =-1;
        }
        result->vertices[i] = NULL;
    }
    return result;
}

graph graph_free(graph g){
    int i;
    for(i=0; i<g->num_vertex;i++){
        free(g->edges[i]);
    }
    free(g->edges);
    free(g->vertices);
    free(g);
    return g;
}

int add_opposite_edge(graph g, int v1, int v2){
    g->edges[v2][v1]=1;
    return 1;
}

int graph_add_edge(graph g, int v1, int v2){
    g->edges[v1][v2]=1;
    /*if bi-directional*/
    add_opposite_edge(g, v1, v2);
    return 1;
}

void graph_bfs(graph g, int source){
    int i;
    queue q = queue_new();
    int v;
    int u;
    for(i=0; i<g->num_vertex;i++){
        g->vertices[i] = emalloc(sizeof *g->vertices[i]);
        g->vertices[i]->state = UNVISITED;
        g->vertices[i]->distance = -1;
        g->vertices[i]->predecessor = -1;
    }
    g->vertices[source]->state = VISITED_SELF;
    g->vertices[source]->distance = 0;

    enqueue(q, source);
    while(queue_size(q)>0){
        u=dequeue(q);
        for(v=0; v< g->num_vertex;v++){
            /*for each unvisited adjacent vertex of v*/
            if(g->edges[u][v]==1 && IS_UNVISITED(g->vertices[v])){
                g->vertices[v]->state = VISITED_SELF;
                g->vertices[v]->distance = g->vertices[u]->distance +1;
                g->vertices[v]->predecessor = u;
                enqueue(q, v);
            }
        }
        g->vertices[u]->state = VISITED_DESCENDANTS;
    }
}

void graph_print(graph g){
    int i;
    int j;
    printf("adjacency list:\n");
    for(i=0; i<g->num_vertex;i++){
        printf("%d | ",i);
        for(j=0;j<g->num_vertex;j++){
            if(g->edges[i][j]==1){
                printf("%d, ", j);
            }
        }
        printf("\n");
    }
    printf("\n");
    for(i=0; i<g->num_vertex;i++){
        printf("vertex distance pred\n");
        printf("%5d %5d %5d\n", i, g->vertices[i]->distance, g->vertices[i]->predecessor);
    }
}

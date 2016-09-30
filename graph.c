#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "mylib.h"
#include "graph.h"

typedef enum {UNVISITED, VISITED_SELF, VISITED_DESCENDANTS} state_t;

    
struct graphrec{
    int **edges;
    int *vertices;
    int num_vertices;
};


graph graph_new(int vertices){
    int i;
    graph g = emalloc(sizeof * g);
    g->num_vertices = vertices;
    g->edges = emalloc..;
    

}

graph graph_add_edge(){
}

void graph_bfs(graph g, source){
    int i;
    for(i=0; i< q->num_vertices; i++){
        

    }




static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;

    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}


int htable_insert(htable h, char *key){
    unsigned int val = htable_word_to_int(key);
    int index= val%h->capacity;
    int init=index;

    do{
        if(h->keys[index]==NULL){
            h->keys[index] = emalloc((strlen(key)+1) * sizeof key[0]);
            strcpy(h->keys[index], key);
            h->num_keys++;
            return 1;
        }else if(strcmp(h->keys[index], key) != 0){
            index = (index+1)% h->capacity;
        }
    }while(index!=init);

    return 0; 


}

void htable_print(htable h, FILE *stream){
    int i;
    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }

}

void htable_free(htable h){
    int i;
    for(i=0; i< h->capacity; i++){
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}



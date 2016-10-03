#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"
int main(){
    int num_vertex = 8;
    graph g = graph_new(num_vertex);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 4);
    graph_add_edge(g, 5, 1);
    graph_add_edge(g, 5, 2);
    graph_add_edge(g, 2, 6);
    graph_add_edge(g, 5, 6);
    graph_add_edge(g, 2, 3);
    graph_add_edge(g, 6, 3);
    graph_add_edge(g, 3, 7);
    graph_add_edge(g, 6, 7);
    graph_bfs(g, 1);
    graph_print(g);
    graph_free(g);

    return EXIT_SUCCESS;
}

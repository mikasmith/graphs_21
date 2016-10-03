#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "mylib.h"
int main(){
    int num_vertex = 6;
    graph g = graph_new(num_vertex);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 3);
    graph_add_edge(g, 1, 4);
    graph_add_edge(g, 2, 4);
    graph_add_edge(g, 2, 5);
    graph_add_edge(g, 3, 1);
    graph_add_edge(g, 4, 3);
    graph_add_edge(g, 5, 5);
    graph_dfs(g);
    graph_print(g);
    graph_free(g);

    return EXIT_SUCCESS;
}

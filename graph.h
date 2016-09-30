#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdio.h>

typedef struct graphrec *graph;



extern void      graph_free(graph g);
extern int       graph_insert(graph g, char *str);
extern graph     graph_new(int vertices);
extern void      graph_print(graph g, FILE *stream);

#endif

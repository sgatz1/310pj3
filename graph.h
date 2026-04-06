#ifndef GRAPH_H
#define GRAPH_H

#include <cfloat>   // for DBL_MAX
#include <iostream>

struct TAG_VERTEX;
struct TAG_NODE;

typedef TAG_VERTEX* pVERTEX;
typedef TAG_NODE* pNODE;

struct TAG_VERTEX {
    int index;
    double key;
    int pi;
};

struct TAG_NODE {
    int u;
    pVERTEX v;
    double w;
    TAG_NODE* next;
};

void initializeGraph(pVERTEX* vertices, pNODE* adjList[], int n);
void addEdge(pNODE* adjList[], int u, pVERTEX v, double w);
void dijkstra(pVERTEX* vertices, pNODE* adjList[], int startIndex, int n);
void relax(pVERTEX u, pNODE node);

#endif

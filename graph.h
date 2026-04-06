#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cfloat>
using namespace std;

struct TAG_VERTEX {
    int index;
    double key;
    int pi;
};
typedef TAG_VERTEX* pVERTEX;

struct TAG_NODE {
    int u;
    pVERTEX v;
    double w;
    TAG_NODE* next;
};
typedef TAG_NODE* pNODE;

// Graph functions
void initializeGraph(pVERTEX* vertices, pNODE adjList[], int n);
void addEdge(pNODE adjList[], int u, pVERTEX v, double w);
void dijkstra(pVERTEX* vertices, pNODE adjList[], int startIndex, int n);
void relax(pVERTEX u, pNODE node);

#endif

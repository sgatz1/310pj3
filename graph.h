#ifndef GRAPH_H
#define GRAPH_H

#include <cfloat>
#include <cstdio>
#include <cstdlib>

struct TAG_VERTEX;
struct TAG_NODE;

typedef TAG_VERTEX* pVERTEX;
typedef TAG_NODE* pNODE;

struct TAG_VERTEX {
    int index;
    double key;   // For Dijkstra
    int pi;       // predecessor
};

struct TAG_NODE {
    int u;
    pVERTEX v;
    double w;
    pNODE next;
};

void initializeGraph(pVERTEX* vertices, pNODE* adjList[], int n);
void addEdge(pNODE* adjList[], int u, pVERTEX v, double w);
void printGraph(pNODE* adjList[], int n);

// Dijkstra utilities
void relax(pVERTEX u, pNODE node);
void dijkstra(pVERTEX* vertices, pNODE* adjList[], int startIndex, int n);
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif

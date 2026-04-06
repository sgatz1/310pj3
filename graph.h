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
    double key;
    int pi;  // predecessor
};

struct TAG_NODE {
    int u;        // source index
    pVERTEX v;    // pointer to destination vertex
    double w;     // edge weight
    TAG_NODE* next;
};

// Graph functions
void initializeGraph(pVERTEX* vertices, pNODE* adjList[], int n);
void addEdge(pNODE* adjList[], int u, pVERTEX v, double w);
void relax(pVERTEX u, pNODE node);
void dijkstra(pVERTEX* vertices, pNODE* adjList[], int startIndex, int n);
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif

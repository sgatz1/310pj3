#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <cfloat>

struct TAG_VERTEX {
    int index;
    double key;
    int pi; // predecessor
};
typedef TAG_VERTEX* pVERTEX;

struct TAG_NODE {
    pVERTEX v;      // pointer to vertex
    double w;       // weight
    TAG_NODE* next; // next node in adjacency list
};
typedef TAG_NODE* pNODE;

// Graph functions
void initializeGraph(pVERTEX vertices[], pNODE adjList[], int n);
void addEdge(pNODE adjList[], int u, pVERTEX v, double w);
void dijkstra(pVERTEX vertices[], pNODE adjList[], int startIndex, int n);
void relax(pVERTEX u, pNODE node, pVERTEX vertices[]);
void printShortestPath(pVERTEX vertices[], int startIndex, int endIndex);

#endif

#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"

void initializeGraph(pVERTEX* vertices, pNODE* adjList, int n);
void addEdge(pNODE* adjList, int u, int v, double w);
void relax(pVERTEX u, pNODE node, pVERTEX* vertices);
void dijkstra(pVERTEX* vertices, pNODE* adjList, int startIndex, int n);
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif

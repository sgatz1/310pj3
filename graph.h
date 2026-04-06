#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"

// initialize adjacency list for n vertices
void initializeGraph(pVERTEX* vertices, pNODE** adjList, int n);

// add an edge u -> v with weight w
void addEdge(pNODE** adjList, int u, int v, double w);

// dijkstra algorithm
void dijkstra(pVERTEX* vertices, pNODE** adjList, int startIndex, int n);

// print shortest path from start to end
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif // GRAPH_H

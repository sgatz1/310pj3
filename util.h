#pragma once
#ifndef UTIL_H
#define UTIL_H

#include "data_structures.h"
#include "heap.h"

// Graph functions
void initializeGraph(pVERTEX* vertices, pNODE** adjList, int n);
void addEdge(pNODE** adjList, int u, int v, double w);

// Dijkstra
void dijkstra(pVERTEX* vertices, pNODE** adjList, int startIndex, int n);

// Printing
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif // UTIL_H

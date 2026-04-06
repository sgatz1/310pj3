#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"

// Initialize the graph adjacency list
void initializeGraph(pVERTEX* vertices, pNODE** adjList, int n);

// Add an edge to the adjacency list
void addEdge(pNODE** adjList, int u, int v, double w);

// Dijkstra's algorithm
void dijkstra(pVERTEX* vertices, pNODE** adjList, int startIndex, int n);

// Print shortest path from startIndex to endIndex
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif // GRAPH_H

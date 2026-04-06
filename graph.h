#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"

// initialize graph
void initializeGraph(pVERTEX* vertices, pNODE* adjList, int n);

// add edge
void addEdge(pNODE* adjList, int u, int v, double w);

// dijkstra algorithm
void dijkstra(pVERTEX* vertices, pNODE* adjList, int startIndex, int n);

// print shortest path
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif // GRAPH_H

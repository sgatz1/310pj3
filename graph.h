#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "data_structures.h"

// initialize single-source distances
void initializeSingleSource(pVERTEX* vertices, int n, int startIndex);

// relax edges
void relax(pVERTEX u, pNODE node);

// dijkstra algorithm
void dijkstra(pVERTEX* vertices, pNODE* adjList, int startIndex, int n);

// print shortest path
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex);

#endif // GRAPH_H

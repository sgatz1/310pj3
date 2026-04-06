#include "graph.h"
#include <cstdio>

void initializeGraph(pVERTEX* vertices, pNODE* adjList, int n) {
    for (int i = 0; i < n; ++i) {
        vertices[i] = new TAG_VERTEX{i, DBL_MAX, -1};
        adjList[i] = nullptr;
    }
}

void addEdge(pNODE* adjList, int u, int v, double w) {
    pNODE newNode = new TAG_NODE{u, v, w, adjList[u]};
    adjList[u] = newNode;
}

void relax(pVERTEX u, pNODE node, pVERTEX* vertices) {
    if (node && u->key + node->w < vertices[node->v]->key) {
        vertices[node->v]->key = u->key + node->w;
        vertices[node->v]->pi = u->index;
    }
}


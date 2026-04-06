#include "graph.h"
#include <cfloat>  // for DBL_MAX

// Relaxation for Dijkstra
void relax(pVERTEX u, pNODE node, pVERTEX* vertices) {
    if (node && u->key + node->w < node->v->key) {
        node->v->key = u->key + node->w;
        node->v->pi = u->index;
    }
}

// Add edge to adjacency list
void addEdge(pNODE* adjList, int u, int v, double w, pVERTEX* vertices) {
    pNODE newNode = new NODE;
    newNode->u = u;
    newNode->v = vertices[v];
    newNode->w = w;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Initialize adjacency list
void initializeGraph(pVERTEX* vertices, pNODE* adjList, int n) {
    for (int i = 0; i < n; i++) {
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        adjList[i] = nullptr;
    }
}

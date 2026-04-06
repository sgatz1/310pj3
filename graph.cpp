#include "graph.h"
#include <cstdio>
#include <cfloat>

// Initialize vertices and adjacency list
void initializeGraph(pVERTEX* vertices, pNODE* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        vertices[i] = new VERTEX{i, DBL_MAX, -1};
        adjList[i] = nullptr;  // empty adjacency list
    }
}

// Add an edge to adjacency list
void addEdge(pNODE* adjList[], int u, pVERTEX v, double w) {
    pNODE newNode = new NODE{u, v, w, nullptr};

    // Insert at rear
    if (!adjList[u]) {
        adjList[u] = newNode;
    } else {
        pNODE curr = adjList[u];
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

// Relax operation for Dijkstra
void relax(pVERTEX u, pNODE node) {
    if (node && u->key + node->w < node->v->key) {
        node->v->key = u->key + node->w;
        node->v->pi = u->index;
    }
}

// Simple Dijkstra (no heap)
void dijkstra(pVERTEX* vertices, pNODE* adjList[], int startIndex, int n) {
    vertices[startIndex]->key = 0;

    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    for (int count = 0; count < n; count++) {
        // Find vertex with minimum key not yet visited
        double minKey = DBL_MAX;
        int uIndex = -1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && vertices[i]->key < minKey) {
                minKey = vertices[i]->key;
                uIndex = i;
            }

        if (uIndex == -1) break;
        visited[uIndex] = true;

        // Relax all neighbors
        for (pNODE node = adjList[uIndex]; node != nullptr; node = node->next) {
            relax(vertices[uIndex], node);
        }
    }
}

// Print path from start to end
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex) {
    if (startIndex == endIndex) {
        printf("%d ", startIndex);
        return;
    }
    if (vertices[endIndex]->pi == -1) {
        printf("No path from %d to %d\n", startIndex, endIndex);
        return;
    }
    printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
    printf("%d ", endIndex);
}

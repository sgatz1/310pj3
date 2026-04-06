#include "util.h"
#include "heap.h"
#include <cfloat>   // DBL_MAX
#include <cstdlib>  // nullptr
#include <cstdio>   // printf

// Relax function
void relax(pVERTEX u, pNODE node, pVERTEX* vertices) {
    pVERTEX v = vertices[node->v];
    if (v->key > u->key + node->w) {
        v->key = u->key + node->w;
        v->pi = u->index;
    }
}

// Dijkstra's algorithm
void dijkstra(pVERTEX* vertices, pNODE* adjList, int startIndex, int n) {
    // Initialize vertices
    for (int i = 0; i < n; i++) {
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->color = WHITE;
    }
    vertices[startIndex]->key = 0;

    // Create min-heap
    HEAP* H = createHeap(n);
    for (int i = 0; i < n; i++) {
        insertHeap(H, vertices[i]);  // use your heap insertion function
    }

    // Main loop
    while (!isEmpty(H)) {
        pVERTEX u = extractMin(H);
        u->color = BLACK;

        for (pNODE node = adjList[u->index]; node != nullptr; node = node->next) {
            relax(u, node, vertices);
        }
    }

    freeHeap(H);
}

// Initialize graph
void initializeGraph(pVERTEX* vertices, pNODE* adjList, int n) {
    for (int i = 0; i < n; i++) {
        vertices[i] = new VERTEX;
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->position = -1;
        adjList[i] = nullptr;
    }
}

// Add edge
void addEdge(pNODE* adjList, int u, int v, double w) {
    pNODE newNode = new NODE;
    newNode->index = 0;
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Print shortest path
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex) {
    if (endIndex == startIndex) {
        printf("%d ", startIndex);
    } else if (vertices[endIndex]->pi == -1) {
        printf("No path from %d to %d\n", startIndex, endIndex);
    } else {
        printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
        printf("%d ", endIndex);
    }
}

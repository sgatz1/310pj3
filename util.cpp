#include "util.h"
#include "data_structures.h"
#include "heap.h"
#include <iostream>
#include <cfloat>

// add an edge to the adjacency list
void addEdge(pNODE* adjList, int u, int v, double w) {
    pNODE newNode = new NODE;
    newNode->index = 0;  // optional, can be ignored
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// initialize single source
void initializeSingleSource(pVERTEX* vertices, int n, int startIndex) {
    for (int i = 0; i < n; i++) {
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->color = WHITE;
    }
    vertices[startIndex]->key = 0;
}

// relax edge
void relax(pVERTEX u, pNODE node, pVERTEX* vertices) {
    pVERTEX v = vertices[node->v];
    if (v->key > u->key + node->w) {
        v->key = u->key + node->w;
        v->pi = u->index;
    }
}

// Dijkstra algorithm
void dijkstra(pVERTEX* vertices, pNODE* adjList, int startIndex, int n) {
    initializeSingleSource(vertices, n, startIndex);

    HEAP* H = createHeap(n);
    for (int i = 0; i < n; i++) {
        H->arr[i] = vertices[i];
        H->arr[i]->position = i;
    }
    H->size = n;

    while (!isEmpty(H)) {
        pVERTEX u = extractMin(H);
        for (pNODE node = adjList[u->index]; node != nullptr; node = node->next) {
            relax(u, *node, vertices);
        }
    }
    freeHeap(H);
}

// print shortest path recursively
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex) {
    if (endIndex == startIndex) {
        std::cout << startIndex;
    } else if (vertices[endIndex]->pi == -1) {
        std::cout << "No path";
    } else {
        printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
        std::cout << " -> " << endIndex;
    }
}

// optional: initialize graph function for main
void initializeGraph(pVERTEX* vertices, pNODE* adjList, int n) {
    for (int i = 0; i < n; i++) {
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->color = WHITE;
        adjList[i] = nullptr;
    }
}

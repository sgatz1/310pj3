#include "graph.h"
#include <iostream>
#include <cstdlib>

void initializeGraph(pVERTEX* &vertices, pNODE* &adjList, int n) {
    vertices = new pVERTEX[n];
    adjList = new pNODE[n];
    for (int i = 0; i < n; i++) {
        vertices[i] = new VERTEX{ i, WHITE, 1e9, -1, -1 };
        adjList[i] = nullptr;
    }
}

void addEdge(pNODE* adjList, int u, int v, double w) {
    pNODE newNode = new NODE{ -1, u, v, w, adjList[u] };
    adjList[u] = newNode;
}

void printGraph(pVERTEX* vertices, pNODE* adjList, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Vertex " << i << ":";
        pNODE curr = adjList[i];
        while (curr != nullptr) {
            std::cout << " -> (" << curr->v << ", " << curr->w << ")";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

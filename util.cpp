#include "util.h"
#include <iostream>
#include <limits>
#include <cstdlib>

void initializeGraph(pVERTEX* vertices, pNODE** adjList, int n) {
    for (int i = 0; i < n; i++) {
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = std::numeric_limits<double>::infinity();
        vertices[i]->pi = -1;
        vertices[i]->position = -1;
        adjList[i] = nullptr;
    }
}

void addEdge(pNODE** adjList, int u, int v, double w) {
    pNODE newNode = new NODE{0, u, v, w, adjList[u]};
    adjList[u] = newNode;
}

void dijkstra(pVERTEX* vertices, pNODE** adjList, int startIndex, int n) {
    HEAP* H = createHeap(n);

    for (int i = 0; i < n; i++) {
        vertices[i]->key = std::numeric_limits<double>::infinity();
        insertHeap(H, vertices[i]);
    }

    vertices[startIndex]->key = 0.0;
    decreaseKey(H, startIndex, 0.0);

    while (!isEmpty(H)) {
        pVERTEX u = extractMin(H);
        for (pNODE node = adjList[u->index]; node != nullptr; node = node->next) {
            pVERTEX v = vertices[node->v];
            if (v->key > u->key + node->w) {
                v->key = u->key + node->w;
                v->pi = u->index;
                decreaseKey(H, v->position, v->key);
            }
        }
    }

    freeHeap(H);
}

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

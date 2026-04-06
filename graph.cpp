#include "graph.h"
#include <iostream>
#include <cfloat>  // for DBL_MAX

using namespace std;

void initializeGraph(pVERTEX* vertices, pNODE* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        vertices[i] = new TAG_VERTEX{i, DBL_MAX, -1};
        adjList[i] = nullptr;
    }
}

void addEdge(pNODE* adjList[], int u, pVERTEX v, double w) {
    pNODE newNode = new TAG_NODE{u, v, w, nullptr};
    if (!adjList[u]) {
        adjList[u] = newNode;
    } else {
        TAG_NODE* curr = adjList[u];
        while (curr->next)
            curr = curr->next;
        curr->next = newNode;
    }
}

void relax(pVERTEX u, pNODE node) {
    if (node && u->key + node->w < node->v->key) {
        node->v->key = u->key + node->w;
        node->v->pi = u->index;
    }
}

void dijkstra(pVERTEX* vertices, pNODE* adjList[], int startIndex, int n) {
    vertices[startIndex]->key = 0.0;

    bool visited[n] = {false};

    for (int i = 0; i < n; i++) {
        int uIndex = -1;
        double minKey = DBL_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && vertices[j]->key < minKey) {
                minKey = vertices[j]->key;
                uIndex = j;
            }
        }

        if (uIndex == -1) break;

        visited[uIndex] = true;

        for (pNODE node = adjList[uIndex]; node != nullptr; node = node->next) {
            relax(vertices[uIndex], node);
        }
    }
}

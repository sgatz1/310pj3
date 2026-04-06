#include "graph.h"
#include <iostream>
using namespace std;

void initializeGraph(pVERTEX vertices[], pNODE adjList[], int n) {
    for (int i = 0; i < n; i++) {
        vertices[i] = new TAG_VERTEX{ i, DBL_MAX, -1 };
        adjList[i] = nullptr;
    }
}

void addEdge(pNODE adjList[], int u, pVERTEX v, double w) {
    pNODE newNode = new TAG_NODE{ v, w, nullptr };

    // Insert at the end of adjacency list
    if (!adjList[u]) {
        adjList[u] = newNode;
    } else {
        pNODE curr = adjList[u];
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

void relax(pVERTEX u, pNODE node, pVERTEX vertices[]) {
    if (node && u->key + node->w < node->v->key) {
        node->v->key = u->key + node->w;
        node->v->pi = u->index;
    }
}

void dijkstra(pVERTEX vertices[], pNODE adjList[], int startIndex, int n) {
    vertices[startIndex]->key = 0;

    // Simple unoptimized Dijkstra
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    for (int count = 0; count < n; count++) {
        // Find minimum key among unvisited
        double minKey = DBL_MAX;
        int uIndex = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && vertices[i]->key < minKey) {
                minKey = vertices[i]->key;
                uIndex = i;
            }
        }

        if (uIndex == -1) break;
        visited[uIndex] = true;
        pNODE node = adjList[uIndex];
        while (node) {
            relax(vertices[uIndex], node, vertices);
            node = node->next;
        }
    }
}

void printShortestPath(pVERTEX vertices[], int startIndex, int endIndex) {
    if (endIndex == startIndex) {
        cout << startIndex << " ";
    } else if (vertices[endIndex]->pi == -1) {
        cout << "No path from " << startIndex << " to " << endIndex << endl;
    } else {
        printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
        cout << endIndex << " ";
    }
}

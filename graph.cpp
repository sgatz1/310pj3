#include "graph.h"

void initializeGraph(pVERTEX* vertices, pNODE* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        vertices[i]->index = i;
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        adjList[i] = nullptr;
    }
}

void addEdge(pNODE* adjList[], int u, pVERTEX v, double w) {
    TAG_NODE* newNode = new TAG_NODE;
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = nullptr;

    if (!adjList[u]) {
        adjList[u] = newNode;
    } else {
        TAG_NODE* curr = adjList[u];
        while (curr->next) curr = curr->next;
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
    vertices[startIndex]->key = 0;

    // Simple array-based selection for minimum (for clarity)
    bool visited[n];
    for (int i = 0; i < n; i++) visited[i] = false;

    for (int count = 0; count < n; count++) {
        // Find min key among unvisited
        double minKey = DBL_MAX;
        int uIndex = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && vertices[i]->key <= minKey) {
                minKey = vertices[i]->key;
                uIndex = i;
            }
        }

        if (uIndex == -1) break; // All reachable vertices visited
        visited[uIndex] = true;

        for (TAG_NODE* node = adjList[uIndex]; node != nullptr; node = node->next) {
            relax(vertices[uIndex], node);
        }
    }
}

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

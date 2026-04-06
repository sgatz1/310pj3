graph.cpp
#include "graph.h"

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
        pNODE current = adjList[u];
        while (current->next) current = current->next;
        current->next = newNode;
    }
}

void printGraph(pNODE* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        printf("ADJ[%d]:", i + 1);
        for (pNODE node = adjList[i]; node != nullptr; node = node->next) {
            printf("-->[ %d %.2f ]", node->v->index + 1, node->w);
        }
        printf("\n");
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

    bool visited[n] = {false};

    for (int i = 0; i < n; i++) {
        // find min key
        double minKey = DBL_MAX;
        int uIndex = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && vertices[j]->key < minKey) {
                minKey = vertices[j]->key;
                uIndex = j;
            }
        }
        if (uIndex == -1) break; // all reachable processed
        visited[uIndex] = true;
        for (pNODE node = adjList[uIndex]; node != nullptr; node = node->next) {
            relax(vertices[uIndex], node);
        }
    }
}

void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex) {
    if (endIndex == startIndex) {
        printf("%d ", startIndex + 1);
    } else if (vertices[endIndex]->pi == -1) {
        printf("No path from %d to %d\n", startIndex + 1, endIndex + 1);
    } else {
        printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
        printf("%d ", endIndex + 1);
    }
}

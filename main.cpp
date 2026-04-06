#include <cstdio>
#include "graph.h"
#include <cfloat>

int main() {
    int n = 5;
    pVERTEX* vertices = new pVERTEX[n];
    pNODE* adjList = new pNODE[n];

    initializeGraph(vertices, adjList, n);

    addEdge(adjList, 0, 1, 2.0);
    addEdge(adjList, 0, 2, 4.0);
    addEdge(adjList, 1, 2, 1.0);
    addEdge(adjList, 1, 3, 7.0);
    addEdge(adjList, 2, 4, 3.0);
    addEdge(adjList, 3, 4, 1.0);

    dijkstra(vertices, adjList, 0, n);

    for (int i = 0; i < n; ++i) {
        printf("Vertex %d: shortest distance = %.2f, path = ", i, vertices[i]->key);
        printShortestPath(vertices, 0, i);
        printf("\n");
    }

    // clean up
    for (int i = 0; i < n; ++i) delete vertices[i];
    for (int i = 0; i < n; ++i) {
        pNODE node = adjList[i];
        while (node) {
            pNODE temp = node;
            node = node->next;
            delete temp;
        }
    }
    delete[] vertices;
    delete[] adjList;

    return 0;
}
}

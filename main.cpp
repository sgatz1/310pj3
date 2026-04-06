#include "graph.h"
#include <cfloat>
#include <cstdio>
#include <cstdlib>

int main() {
    int n = 5; // number of vertices
    pVERTEX vertices[n];
    pNODE* adjList[n];

    // Allocate vertices
    for (int i = 0; i < n; i++) {
        vertices[i] = new TAG_VERTEX;
    }

    initializeGraph(vertices, adjList, n);

    // Add edges
    addEdge(adjList, 0, vertices[1], 2.0);
    addEdge(adjList, 0, vertices[2], 4.0);
    addEdge(adjList, 1, vertices[2], 1.0);
    addEdge(adjList, 1, vertices[3], 7.0);
    addEdge(adjList, 2, vertices[4], 3.0);
    addEdge(adjList, 3, vertices[4], 1.0);

    dijkstra(vertices, adjList, 0, n);

    // Print shortest paths from vertex 0
    for (int i = 0; i < n; i++) {
        printf("Shortest path to %d: ", i);
        printShortestPath(vertices, 0, i);
        printf("\nDistance: %.2f\n", vertices[i]->key);
    }

    // Clean up
    for (int i = 0; i < n; i++) delete vertices[i];
    for (int i = 0; i < n; i++) {
        TAG_NODE* curr = adjList[i];
        while (curr) {
            TAG_NODE* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }

    return 0;
}

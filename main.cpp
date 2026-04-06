#include <iostream>
#include "graph.h"
#include "data_structures.h"

int main() {
    int n = 5; // number of vertices
    pVERTEX* vertices = new pVERTEX[n];

    // Initialize vertices
    for (int i = 0; i < n; i++) {
        vertices[i] = new VERTEX;
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->position = -1;
    }

    // Create adjacency list
    pNODE* adjList = new pNODE[n];
    for (int i = 0; i < n; i++) adjList[i] = nullptr;

    // Initialize graph and add edges
    initializeGraph(vertices, adjList, n);
    addEdge(adjList, 0, 1, 2.0);
    addEdge(adjList, 0, 2, 4.0);
    addEdge(adjList, 1, 2, 1.0);
    addEdge(adjList, 1, 3, 7.0);
    addEdge(adjList, 2, 4, 3.0);
    addEdge(adjList, 3, 4, 1.0);

    // Run Dijkstra from vertex 0
    dijkstra(vertices, adjList, 0, n);

    // Print shortest paths
    for (int i = 0; i < n; i++) {
        std::cout << "Shortest path to vertex " << i << ": ";
        printShortestPath(vertices, 0, i);
        std::cout << std::endl;
    }

    // Free memory
    for (int i = 0; i < n; i++) delete vertices[i];
    delete[] vertices;

    for (int i = 0; i < n; i++) {
        pNODE current = adjList[i];
        while (current) {
            pNODE temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] adjList;

    return 0;
}

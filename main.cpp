#include <iostream>
#include "data_structures.h"
#include "graph.h"
#include "util.h"

int main() {
    int n = 5; // example number of vertices
    pVERTEX* vertices;
    pNODE* adjList;

    initializeGraph(vertices, adjList, n);

    addEdge(adjList, 0, 1, 2.0);
    addEdge(adjList, 0, 2, 4.0);
    addEdge(adjList, 1, 2, 1.0);
    addEdge(adjList, 1, 3, 7.0);
    addEdge(adjList, 2, 4, 3.0);
    addEdge(adjList, 3, 4, 1.0);

    dijkstra(vertices, adjList, 0, n);

    for (int i = 0; i < n; i++) {
        std::cout << "Shortest path to " << i << ": ";
        printShortestPath(vertices, 0, i);
    }

    // Free memory
    for (int i = 0; i < n; i++) {
        delete vertices[i];
        pNODE curr = adjList[i];
        while (curr) {
            pNODE temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] vertices;
    delete[] adjList;

    return 0;
}

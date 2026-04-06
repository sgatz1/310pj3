#include <iostream>
#include "graph.h"
#include "data_structures.h"

int main() {
    const int n = 5;  // number of vertices
    pVERTEX vertices[n];
    pNODE* adjList[n];

    initializeGraph(vertices, adjList, n);

    // Add edges
    addEdge(adjList, 0, vertices[1], 2.0);
    addEdge(adjList, 0, vertices[2], 4.0);
    addEdge(adjList, 1, vertices[2], 1.0);
    addEdge(adjList, 1, vertices[3], 7.0);
    addEdge(adjList, 2, vertices[4], 3.0);
    addEdge(adjList, 3, vertices[4], 1.0);

    dijkstra(vertices, adjList, 0, n);

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        std::cout << "ADJ[" << i << "]:";
        for (pNODE curr = adjList[i]; curr != nullptr; curr = curr->next) {
            std::cout << "-->[" << curr->u << " " << curr->v->index
                      << ": " << curr->w << "]";
        }
        std::cout << "\n";
    }

    // Print shortest paths from vertex 0
    std::cout << "\nShortest paths from 0:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Path to " << i << ": ";
        printShortestPath(vertices, 0, i);
        std::cout << "\n";
    }

    return 0;
}

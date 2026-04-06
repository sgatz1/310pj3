#include <iostream>
#include <cfloat>
#include "graph.h"
using namespace std;

int main() {
    const int n = 5; // number of vertices
    pVERTEX vertices[n];
    pNODE adjList[n];

    initializeGraph(vertices, adjList, n);

    // Add edges (example)
    addEdge(adjList, 0, vertices[1], 2.0);
    addEdge(adjList, 0, vertices[2], 4.0);
    addEdge(adjList, 1, vertices[2], 1.0);
    addEdge(adjList, 1, vertices[3], 7.0);
    addEdge(adjList, 2, vertices[4], 3.0);
    addEdge(adjList, 3, vertices[4], 1.0);

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << "ADJ[" << i << "]:";
        pNODE curr = adjList[i];
        while (curr) {
            cout << "-->[" << i << " " << curr->v->index << ": " << curr->w << "]";
            curr = curr->next;
        }
        cout << endl;
    }

    // Run Dijkstra from vertex 0
    dijkstra(vertices, adjList, 0, n);

    // Print shortest path to vertex 4
    cout << "Shortest path from 0 to 4: ";
    printShortestPath(vertices, 0, 4);
    cout << endl;

    return 0;
]

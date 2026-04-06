#include <iostream>
#include <cfloat>
#include "graph.h"
using namespace std;

int main() {
    const int n = 5;
    pVERTEX vertices[n];
    pNODE adjList[n];  // Correct: array of TAG_NODE*

    initializeGraph(vertices, adjList, n);

    addEdge(adjList, 0, vertices[1], 2.0);
    addEdge(adjList, 0, vertices[2], 4.0);
    addEdge(adjList, 1, vertices[2], 1.0);
    addEdge(adjList, 1, vertices[3], 7.0);
    addEdge(adjList, 2, vertices[4], 3.0);
    addEdge(adjList, 3, vertices[4], 1.0);

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << "ADJ[" << i + 1 << "]:";
        for (pNODE curr = adjList[i]; curr != nullptr; curr = curr->next) {
            cout << "-->[" << curr->u + 1 << " " << curr->v->index + 1 << ": " << curr->w << "]";
        }
        cout << endl;
    }

    dijkstra(vertices, adjList, 0, n);

    // Print shortest paths (optional)
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i + 1 << " key: " << vertices[i]->key << endl;
    }

    return 0;
}

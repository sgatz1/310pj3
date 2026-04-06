#include "graph.h"
#include <cfloat>  // for DBL_MAX
#include <iostream>
using namespace std;

int main() {
    const int n = 5;
    pVERTEX vertices[n];
    pNODE* adjList[n];

    initializeGraph(vertices, adjList, n);

    addEdge(adjList, 0, vertices[1], 2.0);
    addEdge(adjList, 0, vertices[2], 4.0);
    addEdge(adjList, 1, vertices[2], 1.0);
    addEdge(adjList, 1, vertices[3], 7.0);
    addEdge(adjList, 2, vertices[4], 3.0);
    addEdge(adjList, 3, vertices[4], 1.0);

    dijkstra(vertices, adjList, 0, n);

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << "ADJ[" << i+1 << "]:";
        for (pNODE curr = adjList[i]; curr != nullptr; curr = curr->next) {
            cout << "-->[" << curr->u+1 << " " << curr->v->index+1 << ": " << curr->w << "]";
        }
        cout << endl;
    }

    // Clean up
    for (int i = 0; i < n; i++) {
        TAG_NODE* curr = adjList[i];
        while (curr) {
            TAG_NODE* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete vertices[i];
    }

    return 0;
}

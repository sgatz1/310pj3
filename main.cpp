#include <iostream>
#include <cfloat>          // <<--- add this for DBL_MAX
#include "data_structures.h"
#include "graph.h"
#include "heap.h"
#include "util.h"

using namespace std;

int main() {
    int n = 5; // number of vertices
    pVERTEX* vertices = new pVERTEX[n];
    pNODE** adjList = new pNODE*[n];

    // initialize vertices
    for (int i = 0; i < n; i++) {
        vertices[i] = new VERTEX;
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = DBL_MAX; // now DBL_MAX is defined
        vertices[i]->pi = -1;
        vertices[i]->position = -1;
        adjList[i] = nullptr;
    }

    // add edges
    addEdge(adjList, 0, 1, 2.0);
    addEdge(adjList, 0, 2, 4.0);
    addEdge(adjList, 1, 2, 1.0);
    addEdge(adjList, 1, 3, 7.0);
    addEdge(adjList, 2, 4, 3.0);
    addEdge(adjList, 3, 4, 1.0);

    // run Dijkstra
    dijkstra(vertices, adjList, 0, n);

    // print shortest path from 0 to 4
    printShortestPath(vertices, 0, 4);

    // cleanup
    for (int i = 0; i < n; i++) {
        delete vertices[i];
        NODE* current = adjList[i];
        while (current) {
            NODE* tmp = current;
            current = current->next;
            delete tmp;
        }
    }
    delete[] vertices;
    delete[] adjList;

    return 0;
}

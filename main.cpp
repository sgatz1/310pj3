#include <iostream>
#include <cfloat>           // For DBL_MAX
#include "data_structures.h"
#include "graph.h"
#include "util.h"

int main() {
    // number of vertices
    int n = 5;

    // allocate vertices
    pVERTEX* vertices = new pVERTEX[n];
    for (int i = 0; i < n; i++) {
        vertices[i] = new VERTEX;
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = DBL_MAX;
        vertices[i]->pi = -1;
        vertices[i]->position = -1;
    }

    // allocate adjacency list
    pNODE* adjList = new pNODE[n];
    for (int i = 0; i < n; i++) {
        adjList[i] = nullptr;
    }

    // initialize graph (optional if you have an init function)
    initializeGraph(vertices, adjList, n);

    // add edges
    addEdge(adjList, 0, 1, 2.0);
    addEdge(adjList, 0, 2, 4.0);
    addEdge(adjList, 1, 2, 1.0);
    addEdge(adjList, 1, 3, 7.0);
    addEdge(adjList, 2, 4, 3.0);
    addEdge(adjList, 3, 4, 1.0);

    // run Dijkstra starting from vertex 0
    dijkstra(vertices, adjList, 0, n);

    // print shortest paths from vertex 0 to all others
    for (int i = 0; i < n; i++) {
        std::cout << "Path from 0 to " << i << ": ";
        printShortestPath(vertices, 0, i);
        std::cout << std::endl;
    }

    // cleanup
    for (int i = 0; i < n; i++) {
        delete vertices[i];
        pNODE current = adjList[i];
        while (current) {
            pNODE tmp = current;
            current = current->next;
            delete tmp;
        }
    }
    delete[] vertices;
    delete[] adjList;

    return 0;
}

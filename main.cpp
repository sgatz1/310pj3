#include <iostream>
#include "data_structures.h"
#include "graph.h"

int main() {
    int n = 5;
    // allocate vertex array
    pVERTEX* vertices = new pVERTEX[n];
    for (int i = 0; i < n; ++i)
        vertices[i] = new VERTEX;

    // allocate adjacency list (array of pNODE)
    pNODE* adjList = new pNODE[n]; // this is pNODE** when passed
     
    initializeGraph(vertices, adjList, n);

    // add edges
    addEdge(adjList, 0, 1, 2.0);
    addEdge(adjList, 0, 2, 4.0);
    addEdge(adjList, 1, 2, 1.0);
    addEdge(adjList, 1, 3, 7.0);
    addEdge(adjList, 2, 4, 3.0);
    addEdge(adjList, 3, 4, 1.0);

    // run dijkstra from vertex 0
    dijkstra(vertices, adjList, 0, n);

    // print shortest path to vertex 4
    printShortestPath(vertices, 0, 4);
    std::cout << std::endl;

    // cleanup
    for (int i = 0; i < n; ++i) {
        delete vertices[i];
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

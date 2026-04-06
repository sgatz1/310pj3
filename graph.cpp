#include <iostream>
#include <limits>
#include "graph.h"
#include "data_structures.h"

// initialize vertices and adjacency list
void initializeGraph(pVERTEX* vertices, pNODE** adjList, int n) {
    for (int i = 0; i < n; ++i) {
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = std::numeric_limits<double>::infinity();
        vertices[i]->pi = -1;
        vertices[i]->position = -1;

        adjList[i] = nullptr; // initialize linked list to empty
    }
}

// add edge u -> v with weight w
void addEdge(pNODE** adjList, int u, int v, double w) {
    pNODE newNode = new NODE;
    newNode->index = v;
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// relax edges
void relax(pVERTEX u, pNODE node, pVERTEX* vertices) {
    pVERTEX v = vertices[node->v];
    if (v->key > u->key + node->w) {
        v->key = u->key + node->w;
        v->pi = u->index;
    }
}

// dijkstra algorithm
void dijkstra(pVERTEX* vertices, pNODE** adjList, int startIndex, int n) {
    vertices[startIndex]->key = 0;

    // simple array-based priority queue
    bool finished[n];
    for (int i = 0; i < n; ++i) finished[i] = false;

    for (int count = 0; count < n; ++count) {
        // find min key vertex
        double minKey = std::numeric_limits<double>::infinity();
        int uIndex = -1;
        for (int i = 0; i < n; ++i) {
            if (!finished[i] && vertices[i]->key < minKey) {
                minKey = vertices[i]->key;
                uIndex = i;
            }
        }
        if (uIndex == -1) break; // all done

        finished[uIndex] = true;
        pNODE node = adjList[uIndex];
        while (node != nullptr) {
            relax(vertices[uIndex], node, vertices);
            node = node->next;
        }
    }
}

// print shortest path from start to end
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex) {
    if (endIndex == startIndex) {
        std::cout << startIndex;
    } else if (vertices[endIndex]->pi == -1) {
        std::cout << "No path";
    } else {
        printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
        std::cout << " -> " << endIndex;
    }
}

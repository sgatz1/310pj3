#include "graph.h"
#include <iostream>
#include <limits>
#include <queue>

using namespace std;

// Initialize vertices and adjacency list
void initializeGraph(pVERTEX* vertices, pNODE** adjList, int n) {
    for (int i = 0; i < n; i++) {
        vertices[i] = new VERTEX;
        vertices[i]->index = i;
        vertices[i]->color = WHITE;
        vertices[i]->key = numeric_limits<double>::infinity();
        vertices[i]->pi = -1;
        vertices[i]->position = -1;

        adjList[i] = nullptr;
    }
}

// Add edge u -> v with weight w
void addEdge(pNODE** adjList, int u, int v, double w) {
    pNODE newNode = new NODE;
    newNode->u = u;
    newNode->v = v;
    newNode->w = w;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Relax edge u -> v
void relax(pVERTEX* u, pNODE node) {
    pVERTEX v = nullptr; // we will set this in dijkstra
}

// Dijkstra's algorithm
void dijkstra(pVERTEX* vertices, pNODE** adjList, int startIndex, int n) {
    vertices[startIndex]->key = 0;

    // Min-priority queue: pair<key, vertex_index>
    auto cmp = [](pair<double,int> a, pair<double,int> b){ return a.first > b.first; };
    priority_queue<pair<double,int>, vector<pair<double,int>>, decltype(cmp)> pq(cmp);

    pq.push({0, startIndex});

    while (!pq.empty()) {
        auto [dist, uIndex] = pq.top(); pq.pop();
        pNODE node = adjList[uIndex];

        while (node != nullptr) {
            int vIndex = node->v;
            if (vertices[vIndex]->key > vertices[uIndex]->key + node->w) {
                vertices[vIndex]->key = vertices[uIndex]->key + node->w;
                vertices[vIndex]->pi = uIndex;
                pq.push({vertices[vIndex]->key, vIndex});
            }
            node = node->next;
        }
    }
}

// Print shortest path from start to end
void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex) {
    if (endIndex == startIndex) {
        cout << startIndex;
    } else if (vertices[endIndex]->pi == -1) {
        cout << "No path";
    } else {
        printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
        cout << " -> " << endIndex;
    }
}

#include "graph.h"
#include <iostream>
#include <limits>
#include <queue>

// Initialize graph vertices and adjacency list
void initializeGraph(pVERTEX* vertices, pNODE* adjList, int n) {
    for (int i = 0; i < n; i++) {
        vertices[i]->color = WHITE;
        vertices[i]->key = std::numeric_limits<double>::infinity();
        vertices[i]->pi = -1;
        adjList[i] = nullptr;  // no edges yet
    }
}

// Add edge to adjacency list
void addEdge(pNODE* adjList, int u, int v, double w) {
    pNODE node = new NODE;
    node->u = u;
    node->v = v;
    node->w = w;
    node->next = adjList[u];
    adjList[u] = node;
}

// Relax edge u->v
void relax(pVERTEX u, pNODE node) {
    if (node && u->key + node->w < node->v->key) {
        node->v->key = u->key + node->w;
        node->v->pi = u->index;
    }
}

// Dijkstra algorithm
void dijkstra(pVERTEX* vertices, pNODE* adjList, int startIndex, int n) {
    vertices[startIndex]->key = 0;
    
    // Simple priority queue using pair<key, index>
    std::priority_queue<std::pair<double,int>,
                        std::vector<std::pair<double,int>>,
                        std::greater<std::pair<double,int>>> pq;
    
    for (int i = 0; i < n; i++)
        pq.push({vertices[i]->key, i});

    while (!pq.empty()) {
        int u_index = pq.top().second;
        pq.pop();

        pNODE node = adjList[u_index];
        while (node) {
            int v_index = node->v;
            if (vertices[u_index]->key + node->w < vertices[v_index]->key) {
                vertices[v_index]->key = vertices[u_index]->key + node->w;
                vertices[v_index]->pi = u_index;
                pq.push({vertices[v_index]->key, v_index});
            }
            node = node->next;
        }
    }
}

// Print shortest path from start to end
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

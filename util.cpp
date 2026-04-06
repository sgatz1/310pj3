#include "util.h"
#include "heap.h"
#include <iostream>

void initializeSingleSource(pVERTEX* vertices, int n, int s) {
    for (int i = 0; i < n; i++) {
        vertices[i]->key = 1e9;
        vertices[i]->pi = -1;
        vertices[i]->color = WHITE;
    }
    vertices[s]->key = 0;
}

void relax(VERTEX* u, VERTEX* v, double w) {
    if (v->key > u->key + w) {
        v->key = u->key + w;
        v->pi = u->index;
    }
}

void dijkstra(pVERTEX* vertices, pNODE* adjList, int s, int n) {
    initializeSingleSource(vertices, n, s);

    pHEAP H = createHeap(n);
    for (int i = 0; i < n; i++) {
        H->arr[i] = vertices[i];
        H->size++;
    }

    while (!isEmpty(H)) {
        pVERTEX u = extractMin(H);
        pNODE edge = adjList[u->index];
        while (edge != nullptr) {
            relax(u, vertices[edge->v], edge->w);
            edge = edge->next;
        }
    }

    freeHeap(H);
}

void printShortestPath(pVERTEX* vertices, int s, int v) {
    if (v == s) {
        std::cout << s;
    } else if (vertices[v]->pi == -1) {
        std::cout << "No path";
    } else {
        printShortestPath(vertices, s, vertices[v]->pi);
        std::cout << " -> " << v;
    }
    std::cout << std::endl;
}

#include "graph.h"

Graph::Graph(int nodes) : n(nodes) {
    adjList.resize(n);
}

void Graph::addEdge(int from, int to, double weight) {
    Edge e = { to, weight };
    adjList[from].push_back(e);
}

int Graph::size() const {
    return n;
}

const std::vector<Edge>& Graph::neighbors(int node) const {
    return adjList[node];
}
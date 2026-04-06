#pragma once#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <limits>

struct Edge {
    int to;
    double weight;
};

class Graph {
private:
    int n; // number of nodes
    std::vector<std::vector<Edge>> adjList;

public:
    Graph(int nodes);
    void addEdge(int from, int to, double weight);
    int size() const;
    const std::vector<Edge>& neighbors(int node) const;
};

#endif

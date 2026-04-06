#include "graph.h"
#include "util.h"
#include "stack.h"
#include "heap.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./PJ3 <inputfile>\n";
        return 1;
    }

    std::ifstream fin(argv[1]);
    if (!fin) {
        std::cerr << "Cannot open file " << argv[1] << "\n";
        return 1;
    }

    int n, m;
    fin >> n >> m;
    Graph g(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        double w;
        fin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    // Build adjacency list for dijkstra
    std::vector<std::vector<std::pair<int, double>>> adj(n);
    for (int i = 0; i < n; ++i) {
        for (auto& e : g.neighbors(i)) {
            adj[i].push_back({ e.to, e.weight });
        }
    }

    std::vector<double> dist;
    std::vector<int> prev;

    dijkstra(0, adj, dist, prev); // Run from node 0

    std::cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Node " << i << ": " << dist[i] << "\n";
    }

    std::cout << "\nPaths:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << "Path to " << i << ": ";
        printPath(i, prev);
        std::cout << "\n";
    }

    return 0;
}
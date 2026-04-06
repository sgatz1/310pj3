#include "util.h"
#include <iostream>
#include <queue>
#include <functional>

void dijkstra(int start, const std::vector<std::vector<std::pair<int, double>>>& adj,
    std::vector<double>& dist, std::vector<int>& prev) {
    int n = adj.size();
    dist.assign(n, std::numeric_limits<double>::infinity());
    prev.assign(n, -1);

    using PDI = std::pair<double, int>;
    std::priority_queue<PDI, std::vector<PDI>, std::greater<PDI>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        double d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            double w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push({ dist[v], v });
            }
        }
    }
}

void printPath(int target, const std::vector<int>& prev) {
    if (target == -1) return;
    printPath(prev[target], prev);
    std::cout << target << " ";
}
#pragma 
#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
#include <limits>

void dijkstra(int start, const std::vector<std::vector<std::pair<int, double>>>& adj,
    std::vector<double>& dist, std::vector<int>& prev);

void printPath(int target, const std::vector<int>& prev);

#endif

#include "util.h"
#include <cstdio>

void printShortestPath(pVERTEX* vertices, int startIndex, int endIndex) {
    if (endIndex == startIndex) {
        printf("%d ", startIndex + 1);
    } else if (vertices[endIndex]->pi == -1) {
        printf("No path from %d to %d\n", startIndex + 1, endIndex + 1);
    } else {
        printShortestPath(vertices, startIndex, vertices[endIndex]->pi);
        printf("%d ", endIndex + 1);
    }
}

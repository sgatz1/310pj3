#include "heap.h"
#include <cstdlib>
#include <algorithm>

pHEAP createHeap(int capacity) {
    pHEAP heap = (pHEAP)malloc(sizeof(HEAP));
    heap->capacity = capacity;
    heap->size = 0;
    heap->H = (pELEMENT*)malloc((capacity + 1) * sizeof(pELEMENT));
    return heap;
}

// Add insertHeap, extractMin, decreaseKey using standard min-heap logic

void freeHeap(pHEAP heap) {
    free(heap->H);
    free(heap);
}
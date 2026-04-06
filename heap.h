#pragma once
#include "data_structures.h"

// Min-heap structure
typedef struct TAG_HEAP {
    int size;
    int capacity;
    pELEMENT* arr; // array of ELEMENT pointers
} HEAP;

typedef HEAP* pHEAP;

// Heap functions
pHEAP createHeap(int capacity);
void insertHeap(pHEAP H, pELEMENT item);
pELEMENT extractMin(pHEAP H);
void decreaseKey(pHEAP H, int i, double newKey);
void heapify(pHEAP H, int i);
bool isHeapEmpty(pHEAP H);

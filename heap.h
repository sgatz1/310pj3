#pragma once
#ifndef HEAP_H
#define HEAP_H

#include "data_structures.h"

typedef struct TAG_HEAP {
    pVERTEX* arr;  // array of pointers to vertices
    int size;
    int capacity;
} HEAP, *pHEAP;

// Heap functions
pHEAP createHeap(int capacity);
void freeHeap(pHEAP H);
bool isEmpty(pHEAP H);
void insertHeap(pHEAP H, pVERTEX v);
pVERTEX extractMin(pHEAP H);
void decreaseKey(pHEAP H, int i, double newKey);

#endif // HEAP_H

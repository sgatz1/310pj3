#pragma once
#include "data_structures.h"

typedef VERTEX ELEMENT;
typedef ELEMENT* pELEMENT;

typedef struct TAG_HEAP {
    int capacity;
    int size;
    pELEMENT* H;
} HEAP;

typedef HEAP* pHEAP;

pHEAP createHeap(int capacity);
void insertHeap(pHEAP heap, pELEMENT elem);
pELEMENT extractMin(pHEAP heap);
void decreaseKey(pHEAP heap, int i, double newKey);
void freeHeap(pHEAP heap);



#ifndef HEAP_H
#define HEAP_H

#include <cfloat>
#include <cstdlib>

struct TAG_ELEMENT;
typedef TAG_ELEMENT* pELEMENT;

struct TAG_HEAP {
    int size;
    int capacity;
    pELEMENT* arr;  // array of ELEMENT pointers
};

typedef TAG_HEAP* pHEAP;

pHEAP createHeap(int capacity);
void insert(pHEAP H, pELEMENT item);
pELEMENT extractMin(pHEAP H);
bool isEmpty(pHEAP H);
void freeHeap(pHEAP H);

#endif

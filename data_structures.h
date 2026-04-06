#pragma once
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cfloat>

// Graph structs
enum COLOR { WHITE, GRAY, BLACK };

typedef struct TAG_VERTEX {
    int index;
    COLOR color;
    double key;
    int pi;
    int position; // position in min-heap
} VERTEX;

typedef VERTEX* pVERTEX;

typedef struct TAG_NODE {
    int index;   // edge index
    int u;
    int v;
    double w;
    struct TAG_NODE* next;
} NODE;

typedef NODE* pNODE;

// Stack/Heap structs
typedef struct TAG_ELEMENT {
    int data; // or double if needed
} ELEMENT;

typedef ELEMENT* pELEMENT;

typedef struct TAG_STACK {
    pELEMENT* arr;
    int top;
    int capacity;
} STACK;

typedef STACK* pSTACK;

typedef struct TAG_HEAP {
    pELEMENT* arr;
    int size;
    int capacity;
} HEAP;

typedef HEAP* pHEAP;

#endif // DATA_STRUCTURES_H

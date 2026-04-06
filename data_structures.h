#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cfloat>   // for DBL_MAX
#include <cstdlib>  // for nullptr

// Forward type definitions
typedef struct TAG_VERTEX* pVERTEX;
typedef struct TAG_NODE*   pNODE;
typedef struct TAG_ELEMENT* pELEMENT;
typedef struct TAG_HEAP*    pHEAP;
typedef struct TAG_STACK*   pSTACK;

// Vertex structure
typedef struct TAG_VERTEX {
    int index;        // vertex ID
    double key;       // distance for Dijkstra
    int pi;           // predecessor index
} VERTEX;

// Node structure (for adjacency list)
typedef struct TAG_NODE {
    int u;            // source vertex index
    pVERTEX v;        // pointer to destination vertex
    double w;         // edge weight
    pNODE next;       // next node in adjacency list
} NODE;

// Heap element (for priority queue in Dijkstra)
typedef struct TAG_ELEMENT {
    pVERTEX vertex;
    double key;
} ELEMENT;

// Heap structure
typedef struct TAG_HEAP {
    int size;        // current size
    int capacity;    // max capacity
    pELEMENT* arr;   // array of ELEMENT pointers
} HEAP;

// Stack structure
typedef struct TAG_STACK {
    int top;
    int capacity;
    pELEMENT* arr;   // array of ELEMENT pointers
} STACK;

#endif // DATA_STRUCTURES_H

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <cfloat>   // DBL_MAX
#include <cstdlib>  // nullptr

struct TAG_VERTEX {
    int index;
    double key;
    int pi; // predecessor
};
typedef TAG_VERTEX* pVERTEX;

struct TAG_NODE {
    int u;
    int v;
    double w;
    TAG_NODE* next;
};
typedef TAG_NODE* pNODE;

#endif

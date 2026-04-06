#pragma once
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

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
    TAG_NODE* next;
} NODE;

typedef NODE* pNODE;

#endif // DATA_STRUCTURES_H

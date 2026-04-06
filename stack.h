#pragma once
#ifndef STACK_H
#define STACK_H

#include "data_structures.h" // ensures TAG_VERTEX is defined

// define stack element as VERTEX pointer
typedef TAG_VERTEX ELEMENT;
typedef ELEMENT* pELEMENT;

typedef struct TAG_STACK {
    int top;
    int capacity;
    pELEMENT* arr;  // array of ELEMENT pointers
} STACK, *pSTACK;

pSTACK createStack(int capacity);
void push(pSTACK S, pELEMENT item);
pELEMENT pop(pSTACK S);
bool isEmptyStack(pSTACK S);
void freeStack(pSTACK S);

#endif // STACK_H

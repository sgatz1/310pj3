#pragma once
#ifndef STACK_H
#define STACK_H

#include "data_structures.h"

typedef struct TAG_STACK {
    int capacity;
    int top;
    pELEMENT* arr;
} STACK;

typedef STACK* pSTACK;

pSTACK createStack(int capacity);
void push(pSTACK S, pELEMENT item);
pELEMENT pop(pSTACK S);
bool isEmpty(pSTACK S);
void freeStack(pSTACK S);

#endif // STACK_H

#pragma once
#include "data_structures.h"
#include <stdbool.h>

// Stack structure
typedef struct TAG_STACK {
    int top;
    int capacity;
    pELEMENT* arr;  // array of ELEMENT pointers
} STACK;

typedef STACK* pSTACK;

// Stack functions
pSTACK createStack(int capacity);
void push(pSTACK S, pELEMENT item);
pELEMENT pop(pSTACK S);
bool isEmpty(pSTACK S);
bool isFull(pSTACK S);

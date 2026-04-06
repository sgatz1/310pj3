#include "stack.h"
#include <cstdlib> // for nullptr

pSTACK createStack(int capacity) {
    pSTACK S = new STACK;
    S->top = -1;
    S->capacity = capacity;
    S->arr = new pELEMENT[capacity];  // array of ELEMENT pointers
    return S;
}

void push(pSTACK S, pELEMENT item) {
    if (S->top + 1 < S->capacity)
        S->arr[++S->top] = item;
}

pELEMENT pop(pSTACK S) {
    if (S->top >= 0)
        return S->arr[S->top--];
    return nullptr;
}

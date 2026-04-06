#include "stack.h"
#include <cstdlib>
#include <iostream>

pSTACK createStack(int capacity) {
    pSTACK S = new STACK;
    S->top = -1;
    S->capacity = capacity;
    S->arr = new pELEMENT[capacity];
    return S;
}

void push(pSTACK S, pELEMENT item) {
    if (S->top < S->capacity - 1)
        S->arr[++S->top] = item;
}

pELEMENT pop(pSTACK S) {
    if (S->top >= 0)
        return S->arr[S->top--];
    return nullptr;
}

bool isEmpty(pSTACK S) {
    return S->top == -1;
}

void freeStack(pSTACK S) {
    delete[] S->arr;
    delete S;
}

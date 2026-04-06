#include "stack.h"
#include <cstdlib>

pSTACK createStack(int capacity) {
    pSTACK S = new TAG_STACK{ -1, capacity, new pELEMENT[capacity] };
    return S;
}

void push(pSTACK S, pELEMENT item) {
    if (S->top + 1 >= S->capacity) return;
    S->arr[++S->top] = item;
}

pELEMENT pop(pSTACK S) {
    if (S->top < 0) return nullptr;
    return S->arr[S->top--];
}

void freeStack(pSTACK S) {
    delete[] S->arr;
    delete S;
}

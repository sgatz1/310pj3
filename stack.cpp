#include "stack.h"
#include <cstdlib>
#include "heap.h"

pSTACK createStack(int capacity) {
    pSTACK stack = (pSTACK)malloc(sizeof(STACK));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (pELEMENT*)malloc(capacity * sizeof(pELEMENT));
    return stack;
}

void push(pSTACK stack, pELEMENT elem) {
    if (stack->top < stack->capacity - 1)
        stack->arr[++stack->top] = elem;
}

pELEMENT pop(pSTACK stack) {
    if (stack->top >= 0) return stack->arr[stack->top--];
    return nullptr;
}

bool isEmpty(pSTACK stack) { return stack->top == -1; }

void freeStack(pSTACK stack) {
    free(stack->arr);
    free(stack);
}
#ifndef STACK_H
#define STACK_H

struct TAG_ELEMENT;
typedef TAG_ELEMENT* pELEMENT;

struct TAG_STACK {
    int top;
    int capacity;
    pELEMENT* arr;
};

typedef TAG_STACK* pSTACK;

pSTACK createStack(int capacity);
void push(pSTACK S, pELEMENT item);
pELEMENT pop(pSTACK S);
void freeStack(pSTACK S);

#endif

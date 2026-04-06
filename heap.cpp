#include "heap.h"
#include <limits>
#include <cstdlib>

pHEAP createHeap(int capacity) {
    pHEAP H = new HEAP;
    H->arr = new pVERTEX[capacity];
    H->size = 0;
    H->capacity = capacity;
    return H;
}

void freeHeap(pHEAP H) {
    delete[] H->arr;
    delete H;
}

bool isEmpty(pHEAP H) {
    return H->size == 0;
}

void swap(pVERTEX& a, pVERTEX& b) {
    pVERTEX temp = a;
    a = b;
    b = temp;

    // Update positions
    int tempPos = a->position;
    a->position = b->position;
    b->position = tempPos;
}

// Heapify down
void minHeapify(pHEAP H, int i) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int smallest = i;

    if (left < H->size && H->arr[left]->key < H->arr[smallest]->key)
        smallest = left;
    if (right < H->size && H->arr[right]->key < H->arr[smallest]->key)
        smallest = right;

    if (smallest != i) {
        swap(H->arr[i], H->arr[smallest]);
        minHeapify(H, smallest);
    }
}

pVERTEX extractMin(pHEAP H) {
    if (H->size <= 0) return nullptr;
    pVERTEX min = H->arr[0];
    H->arr[0] = H->arr[H->size - 1];
    H->arr[0]->position = 0;
    H->size--;
    minHeapify(H, 0);
    return min;
}

void decreaseKey(pHEAP H, int i, double newKey) {
    H->arr[i]->key = newKey;
    while (i != 0 && H->arr[(i-1)/2]->key > H->arr[i]->key) {
        int parent = (i-1)/2;
        swap(H->arr[i], H->arr[parent]);
        i = parent;
    }
}

void insertHeap(pHEAP H, pVERTEX v) {
    if (H->size == H->capacity) return; // ignore overflow
    int i = H->size;
    H->arr[i] = v;
    v->position = i;
    H->size++;
    decreaseKey(H, i, v->key);
}

#include "heap.h"
#include <iostream>
#include <cstdlib>

pHEAP createHeap(int capacity) {
    pHEAP H = new HEAP;
    H->size = 0;
    H->capacity = capacity;
    H->arr = new pELEMENT[capacity];
    return H;
}

void swap(pELEMENT &a, pELEMENT &b) {
    pELEMENT temp = a;
    a = b;
    b = temp;
}

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

pELEMENT extractMin(pHEAP H) {
    if (H->size == 0) return nullptr;
    pELEMENT min = H->arr[0];
    H->arr[0] = H->arr[H->size - 1];
    H->size--;
    minHeapify(H, 0);
    return min;
}

void decreaseKey(pHEAP H, int i, double key) {
    if (key > H->arr[i]->key) return;
    H->arr[i]->key = key;
    while (i > 0 && H->arr[(i-1)/2]->key > H->arr[i]->key) {
        swap(H->arr[i], H->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

bool isEmpty(pHEAP H) {
    return H->size == 0;
}

void freeHeap(pHEAP H) {
    delete[] H->arr;
    delete H;
}

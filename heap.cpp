#include "heap.h"
#include "data_structures.h"  // Make sure TAG_ELEMENT is defined here
#include <algorithm>
#include <iostream>

using namespace std;

pHEAP createHeap(int capacity) {
    pHEAP H = new TAG_HEAP;
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

void heapify(pHEAP H, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < H->size && H->arr[l]->key < H->arr[smallest]->key)
        smallest = l;
    if (r < H->size && H->arr[r]->key < H->arr[smallest]->key)
        smallest = r;

    if (smallest != i) {
        swap(H->arr[i], H->arr[smallest]);
        heapify(H, smallest);
    }
}

void insert(pHEAP H, pELEMENT elem) {
    if (H->size == H->capacity) {
        cout << "Heap full!\n";
        return;
    }

    int i = H->size++;
    H->arr[i] = elem;

    while (i != 0 && H->arr[(i - 1) / 2]->key > H->arr[i]->key) {
        swap(H->arr[i], H->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

pELEMENT extractMin(pHEAP H) {
    if (H->size <= 0) return nullptr;
    if (H->size == 1) return H->arr[--H->size];

    pELEMENT root = H->arr[0];
    H->arr[0] = H->arr[--H->size];
    heapify(H, 0);

    return root;
}

bool isEmpty(pHEAP H) {
    return H->size == 0;
}

void freeHeap(pHEAP H) {
    delete[] H->arr;
    delete H;
}

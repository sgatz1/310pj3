#include "heap.h"
#include <algorithm>

pHEAP createHeap(int capacity) {
    pHEAP H = new TAG_HEAP{0, capacity, new pELEMENT[capacity]};
    return H;
}

void insert(pHEAP H, pELEMENT item) {
    if (H->size >= H->capacity) return;
    int i = H->size++;
    H->arr[i] = item;
    while (i != 0 && H->arr[(i - 1) / 2]->key > H->arr[i]->key) {
        std::swap(H->arr[i], H->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

pELEMENT extractMin(pHEAP H) {
    if (H->size <= 0) return nullptr;
    pELEMENT root = H->arr[0];
    H->arr[0] = H->arr[--H->size];
    int i = 0;
    while (true) {
        int l = 2 * i + 1, r = 2 * i + 2;
        int smallest = i;
        if (l < H->size && H->arr[l]->key < H->arr[smallest]->key) smallest = l;
        if (r < H->size && H->arr[r]->key < H->arr[smallest]->key) smallest = r;
        if (smallest != i) {
            std::swap(H->arr[i], H->arr[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

bool isEmpty(pHEAP H) {
    return H->size == 0;
}

void freeHeap(pHEAP H) {
    delete[] H->arr;
    delete H;
}

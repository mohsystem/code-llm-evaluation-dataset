// Note: C does not have a built-in priority queue, so we will use a simple array to implement the heap.
#include <stdio.h>

typedef struct {
    int size;
    int capacity;
    int *arr;
} Heap;

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (int*)malloc(sizeof(int) * capacity);
    return heap;
}

void heapifyUp(Heap* heap, int index) {
    if (index && heap->arr[index] > heap->arr[(index - 1) / 2]) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[(index - 1) / 2];
        heap->arr[(index - 1) / 2] = temp;
        heapifyUp(heap, (index - 1) / 2);
    }
}

void heapifyDown(Heap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < heap->size && heap->arr[left] > heap->arr[largest]) {
        largest = left;
    }
    if (right < heap->size && heap->arr[right] > heap->arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        int temp = heap->arr[index];
        heap->arr[index] = heap->arr[largest];
        heap->arr[largest] = temp;
        heapifyDown(heap, largest);
    }
}

void insert(Heap* heap, int num) {
    if (heap->size == heap->capacity) {
        printf("Heap is full\n");
        return;
    }
    heap->arr[heap->size] = num;
    heap->size++;
    heapifyUp(heap, heap->size - 1);
}

int extractMax(Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty\n");
        return -1;
    }
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}

typedef struct {
    Heap* lower;
    Heap* higher;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* medianFinder = (MedianFinder*)malloc(sizeof(MedianFinder));
    medianFinder->lower = createHeap(100001);
    medianFinder->higher = createHeap(100001);
    return medianFinder;
}

void addNum(MedianFinder* obj, int num) {
    if (obj->lower->size == 0 || num <= obj->lower->arr[0]) {
        insert(obj->lower, num);
    } else {
        insert(obj->higher, num);
    }
    
    if (obj->lower->size > obj->higher->size + 1) {
        insert(obj->higher, extractMax(obj->lower));
    } else if (obj->higher->size > obj->lower->size) {
        insert(obj->lower, extractMax(obj->higher));
    }
}

double findMedian(MedianFinder* obj) {
    if (obj->lower->size == obj->higher->size) {
        return (obj->lower->arr[0] + obj->higher->arr[0]) / 2.0;
    } else {
        return obj->lower->arr[0];
    }
}
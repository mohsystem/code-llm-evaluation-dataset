
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* small;  // max heap
    int* large;  // min heap
    int smallSize;
    int largeSize;
    int capacity;
} MedianFinder;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int* arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void minHeapify(int* arr, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->capacity = 50000;
    obj->small = (int*)malloc(obj->capacity * sizeof(int));
    obj->large = (int*)malloc(obj->capacity * sizeof(int));
    obj->smallSize = 0;
    obj->largeSize = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->smallSize == obj->largeSize) {
        obj->small[obj->smallSize++] = num;
        for (int i = (obj->smallSize / 2) - 1; i >= 0; i--)
            maxHeapify(obj->small, obj->smallSize, i);
        
        obj->large[obj->largeSize++] = obj->small[0];
        obj->small[0] = obj->small[--obj->smallSize];
        for (int i = (obj->largeSize / 2) - 1; i >= 0; i--)
            minHeapify(obj->large, obj->largeSize, i);
    } else {
        obj->large[obj->largeSize++] = num;
        for (int i = (obj->largeSize / 2) - 1; i >= 0; i--)
            minHeapify(obj->large, obj->largeSize, i);
        
        obj->small[obj->smallSize++] = obj->large[0];
        obj->large[0] = obj->large[--obj->largeSize];
        for (int i = (obj->smallSize / 2) - 1; i >= 0; i--)
            maxHeapify(obj->small, obj->smallSize, i);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->smallSize == obj->largeSize) {
        return (obj->small[0] + obj->large[0]) / 2.0;
    } else {
        return obj->large[0];
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->small);
    free(obj->large);
    free(obj);
}

/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 * double param_2 = medianFinderFindMedian(obj);
 * medianFinderFree(obj);
 */

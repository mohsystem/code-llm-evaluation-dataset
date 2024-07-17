#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int* nums;
    int numsSize;
    int capacity;
} MinHeap;

typedef struct {
    int* nums;
    int numsSize;
    int capacity;
} MaxHeap;

MinHeap* minHeapCreate(int capacity);
void minHeapPush(MinHeap* obj, int num);
int minHeapPop(MinHeap* obj);
int minHeapTop(MinHeap* obj);
void minHeapFree(MinHeap* obj);

MaxHeap* maxHeapCreate(int capacity);
void maxHeapPush(MaxHeap* obj, int num);
int maxHeapPop(MaxHeap* obj);
int maxHeapTop(MaxHeap* obj);
void maxHeapFree(MaxHeap* obj);

typedef struct {
    MinHeap* small;
    MaxHeap* large;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->small = minHeapCreate(10000);
    obj->large = maxHeapCreate(10000);
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->small->numsSize == obj->large->numsSize) {
        maxHeapPush(obj->small, num);
        minHeapPush(obj->large, maxHeapPop(obj->small));
    } else {
        minHeapPush(obj->large, num);
        maxHeapPush(obj->small, minHeapPop(obj->large));
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->small->numsSize == obj->large->numsSize) {
        return (minHeapTop(obj->small) + maxHeapTop(obj->large)) / 2.0;
    } else {
        return minHeapTop(obj->small);
    }
}

void medianFinderFree(MedianFinder* obj) {
    minHeapFree(obj->small);
    maxHeapFree(obj->large);
    free(obj);
}
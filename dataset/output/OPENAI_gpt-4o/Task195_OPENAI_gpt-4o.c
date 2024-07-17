#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* small;
    int* large;
    int smallSize;
    int largeSize;
} MedianFinder;

int cmp(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->small = (int*)malloc(10000 * sizeof(int));
    obj->large = (int*)malloc(10000 * sizeof(int));
    obj->smallSize = 0;
    obj->largeSize = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    obj->small[obj->smallSize++] = num;
    qsort(obj->small, obj->smallSize, sizeof(int), cmp);
    
    if (obj->smallSize > obj->largeSize + 1) {
        obj->large[obj->largeSize++] = obj->small[--obj->smallSize];
        qsort(obj->large, obj->largeSize, sizeof(int), cmp);
    }
}

double findMedian(MedianFinder* obj) {
    if (obj->smallSize > obj->largeSize) {
        return obj->small[0];
    } else {
        return (obj->small[0] + obj->large[0]) / 2.0;
    }
}

int main() {
    MedianFinder* medianFinder = medianFinderCreate();
    addNum(medianFinder, 1);
    addNum(medianFinder, 2);
    printf("%lf
", findMedian(medianFinder)); // Output: 1.5
    addNum(medianFinder, 3);
    printf("%lf
", findMedian(medianFinder)); // Output: 2.0
    free(medianFinder->small);
    free(medianFinder->large);
    free(medianFinder);
    return 0;
}
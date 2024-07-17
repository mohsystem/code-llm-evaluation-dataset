#include <stdlib.h>

typedef struct MedianFinder {
    int* lower;
    int lowerSize;
    int* higher;
    int higherSize;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*) malloc(sizeof(MedianFinder));
    obj->lower = (int*) malloc(sizeof(int) * 100001);
    obj->higher = (int*) malloc(sizeof(int) * 100001);
    obj->lowerSize = 0;
    obj->higherSize = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    if (obj->lowerSize == 0 || num <= obj->lower[0]) {
        obj->lower[obj->lowerSize++] = num;
    } else {
        obj->higher[obj->higherSize++] = num;
    }
    
    if (obj->lowerSize > obj->higherSize + 1) {
        obj->higher[obj->higherSize++] = obj->lower[--obj->lowerSize];
    } else if (obj->higherSize > obj->lowerSize) {
        obj->lower[obj->lowerSize++] = obj->higher[--obj->higherSize];
    }
}

double findMedian(MedianFinder* obj) {
    if (obj->lowerSize == obj->higherSize) {
        return (obj->lower[0] + obj->higher[0]) / 2.0;
    } else {
        return obj->lower[0];
    }
}
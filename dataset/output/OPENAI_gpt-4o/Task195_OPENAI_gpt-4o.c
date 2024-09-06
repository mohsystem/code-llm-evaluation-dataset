#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* nums;
    int size;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->nums = NULL;
    obj->size = 0;
    return obj;
}

void addNum(MedianFinder* obj, int num) {
    obj->nums = (int*)realloc(obj->nums, (obj->size + 1) * sizeof(int));
    int i = obj->size - 1;
    while (i >= 0 && obj->nums[i] > num) {
        obj->nums[i + 1] = obj->nums[i];
        i--;
    }
    obj->nums[i + 1] = num;
    obj->size++;
}

double findMedian(MedianFinder* obj) {
    if (obj->size % 2 == 1) {
        return obj->nums[obj->size / 2];
    } else {
        return (obj->nums[obj->size / 2 - 1] + obj->nums[obj->size / 2]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->nums);
    free(obj);
}

int main() {
    MedianFinder* medianFinder = medianFinderCreate();
    addNum(medianFinder, 1);
    addNum(medianFinder, 2);
    printf("%.1f\n", findMedian(medianFinder)); // 1.5
    addNum(medianFinder, 3);
    printf("%.1f\n", findMedian(medianFinder)); // 2.0
    medianFinderFree(medianFinder);
    return 0;
}
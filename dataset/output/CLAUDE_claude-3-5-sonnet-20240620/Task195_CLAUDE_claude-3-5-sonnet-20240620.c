
#include <stdlib.h>

typedef struct {
    int* nums;
    int size;
    int capacity;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->nums = (int*)malloc(sizeof(int) * 50000);
    obj->size = 0;
    obj->capacity = 50000;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->nums = (int*)realloc(obj->nums, sizeof(int) * obj->capacity);
    }
    
    int i = obj->size - 1;
    while (i >= 0 && obj->nums[i] > num) {
        obj->nums[i + 1] = obj->nums[i];
        i--;
    }
    obj->nums[i + 1] = num;
    obj->size++;
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->size % 2 == 0) {
        return (obj->nums[obj->size / 2 - 1] + obj->nums[obj->size / 2]) / 2.0;
    } else {
        return obj->nums[obj->size / 2];
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->nums);
    free(obj);
}

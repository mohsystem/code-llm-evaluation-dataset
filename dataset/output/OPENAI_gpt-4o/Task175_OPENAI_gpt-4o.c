#include <stdio.h>
#include <stdlib.h>

typedef struct MountainArray {
    int* arr;
    int size;
    int calls;
} MountainArray;

MountainArray* createMountainArray(int* arr, int size) {
    MountainArray* mountainArr = (MountainArray*)malloc(sizeof(MountainArray));
    mountainArr->arr = arr;
    mountainArr->size = size;
    mountainArr->calls = 0;
    return mountainArr;
}

int get(MountainArray* mountainArr, int index) {
    mountainArr->calls++;
    if (mountainArr->calls > 100) {
        printf("Too many calls\n");
        exit(1);
    }
    return mountainArr->arr[index];
}

int length(MountainArray* mountainArr) {
    return mountainArr->size;
}

int findPeakIndex(MountainArray* arr) {
    int left = 0, right = length(arr) - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (get(arr, mid) < get(arr, mid + 1)) left = mid + 1;
        else right = mid;
    }
    return left;
}

int binarySearch(MountainArray* arr, int target, int left, int right, int ascending) {
    while (left <= right) {
        int mid = (left + right) / 2;
        int value = get(arr, mid);
        if (value == target) return mid;
        if (value < target) {
            if (ascending) left = mid + 1;
            else right = mid - 1;
        } else {
            if (ascending) right = mid - 1;
            else left = mid + 1;
        }
    }
    return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    int peak = findPeakIndex(mountainArr);
    int index = binarySearch(mountainArr, target, 0, peak, 1);
    if (index != -1) return index;
    return binarySearch(mountainArr, target, peak + 1, length(mountainArr) - 1, 0);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 3, 1};
    MountainArray* mountainArr = createMountainArray(arr, 7);
    printf("%d\n", findInMountainArray(3, mountainArr)); // Output: 2
    free(mountainArr);
    return 0;
}
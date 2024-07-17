#include <stdio.h>

typedef struct {
    int *arr;
    int size;
} MountainArray;

int get(MountainArray* m, int index) {
    return m->arr[index];
}

int length(MountainArray* m) {
    return m->size;
}

int peakIndexInMountainArray(MountainArray* mountainArr) {
    int left = 0, right = mountainArr->size - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int binarySearch(MountainArray* mountainArr, int target, int left, int right, int asc) {
    while (left <= right) {
        int mid = (left + right) / 2;
        int val = get(mountainArr, mid);
        if (val == target) {
            return mid;
        }
        if (asc) {
            if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            if (val > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int findInMountainArray(int target, MountainArray* mountainArr) {
    int peak = peakIndexInMountainArray(mountainArr);
    int result = binarySearch(mountainArr, target, 0, peak, 1);
    if (result != -1) {
        return result;
    }
    return binarySearch(mountainArr, target, peak + 1, mountainArr->size - 1, 0);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 3, 1};
    MountainArray m = {arr, 7};
    printf("%d
", findInMountainArray(3, &m));  // Output: 2

    int arr2[] = {0, 1, 2, 4, 2, 1};
    MountainArray m2 = {arr2, 6};
    printf("%d
", findInMountainArray(3, &m2));  // Output: -1

    return 0;
}
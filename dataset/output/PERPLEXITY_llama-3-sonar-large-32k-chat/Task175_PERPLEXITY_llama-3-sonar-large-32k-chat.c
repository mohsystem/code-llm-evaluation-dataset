// Note: C does not support object-oriented programming, so we cannot use a class to define the solution. 
// Also, C does not have a built-in binary search function, so we need to implement it manually.
#include <stdio.h>

int findInMountainArray(int target, int (*get)(int), int length) {
    int left = 0, right = length - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (get(mid) < get(mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    int peak = left;
    left = 0;
    right = peak;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (get(mid) < target) {
            left = mid + 1;
        } else if (get(mid) > target) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    left = peak;
    right = length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (get(mid) < target) {
            right = mid - 1;
        } else if (get(mid) > target) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
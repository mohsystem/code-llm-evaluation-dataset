#include <stdio.h>

int mergeSort(int nums[], int left, int right) {
    if (left >= right) {
        return 0;
    }
    int mid = left + (right - left) / 2;
    int leftCount = mergeSort(nums, left, mid);
    int rightCount = mergeSort(nums, mid + 1, right);
    int mergedCount = merge(nums, left, mid, right);
    return leftCount + rightCount + mergedCount;
}

int merge(int nums[], int left, int mid, int right) {
    int temp[right - left + 1];
    int leftIndex = left, rightIndex = mid + 1, tempIndex = 0, mergedCount = 0;
    while (leftIndex <= mid && rightIndex <= right) {
        if (nums[leftIndex] <= 2 * nums[rightIndex]) {
            temp[tempIndex++] = nums[leftIndex++];
        } else {
            temp[tempIndex++] = nums[rightIndex++];
            mergedCount += mid - leftIndex + 1;
        }
    }
    while (leftIndex <= mid) {
        temp[tempIndex++] = nums[leftIndex++];
    }
    while (rightIndex <= right) {
        temp[tempIndex++] = nums[rightIndex++];
    }
    for (int i = 0; i < right - left + 1; i++) {
        nums[left + i] = temp[i];
    }
    return mergedCount;
}

int main() {
    int nums[] = {1,3,2,3,1};
    int n = sizeof(nums) / sizeof(nums[0]);
    printf("%d
", mergeSort(nums, 0, n - 1));
    return 0;
}
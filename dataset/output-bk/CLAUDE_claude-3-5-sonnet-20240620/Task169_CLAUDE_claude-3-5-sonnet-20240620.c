
#include <stdlib.h>
#include <string.h>

void merge(int** enum_nums, int* counts, int left, int mid, int right) {
    int** temp = (int**)malloc((right - left + 1) * sizeof(int*));
    for (int i = 0; i < right - left + 1; i++) {
        temp[i] = (int*)malloc(2 * sizeof(int));
    }
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (enum_nums[i][1] <= enum_nums[j][1]) {
            temp[k][0] = enum_nums[i][0];
            temp[k][1] = enum_nums[i][1];
            counts[enum_nums[i][0]] += j - (mid + 1);
            i++;
        } else {
            temp[k][0] = enum_nums[j][0];
            temp[k][1] = enum_nums[j][1];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k][0] = enum_nums[i][0];
        temp[k][1] = enum_nums[i][1];
        counts[enum_nums[i][0]] += right - mid;
        i++;
        k++;
    }
    while (j <= right) {
        temp[k][0] = enum_nums[j][0];
        temp[k][1] = enum_nums[j][1];
        j++;
        k++;
    }
    for (int p = 0; p < right - left + 1; p++) {
        enum_nums[left + p][0] = temp[p][0];
        enum_nums[left + p][1] = temp[p][1];
    }
    for (int i = 0; i < right - left + 1; i++) {
        free(temp[i]);
    }
    free(temp);
}

void merge_sort(int** enum_nums, int* counts, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(enum_nums, counts, left, mid);
    merge_sort(enum_nums, counts, mid + 1, right);
    merge(enum_nums, counts, left, mid, right);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* counts = (int*)calloc(numsSize, sizeof(int));
    int** enum_nums = (int**)malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++) {
        enum_nums[i] = (int*)malloc(2 * sizeof(int));
        enum_nums[i][0] = i;
        enum_nums[i][1] = nums[i];
    }
    merge_sort(enum_nums, counts, 0, numsSize - 1);
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i++) {
        free(enum_nums[i]);
    }
    free(enum_nums);
    return counts;
}

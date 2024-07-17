#include <stdlib.h>

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long* sums = malloc(sizeof(long) * (numsSize + 1));
    sums[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        sums[i + 1] = sums[i] + nums[i];
    }
    int count = countWhileMergeSort(sums, 0, numsSize, lower, upper);
    free(sums);
    return count;
}

int countWhileMergeSort(long* sums, int start, int end, int lower, int upper) {
    if (end <= start) {
        return 0;
    }
    int mid = start + (end - start) / 2;
    int count = countWhileMergeSort(sums, start, mid, lower, upper) + countWhileMergeSort(sums, mid + 1, end, lower, upper);
    int j = mid + 1, k = mid + 1;
    long* cache = malloc(sizeof(long) * (end - start));
    int idx = 0;
    for (int i = start; i <= mid; i++) {
        while (j <= end && sums[j] - sums[i] < lower) {
            j++;
        }
        while (k <= end && sums[k] - sums[i] <= upper) {
            k++;
        }
        count += k - j;
        while (idx < end - start && sums[start + idx] <= sums[i]) {
            cache[idx++] = sums[start + idx];
        }
        cache[idx++] = sums[i];
    }
    for (int i = 0; i < idx; i++) {
        sums[start + i] = cache[i];
    }
    free(cache);
    return count;
}
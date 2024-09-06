// C code
#include <stdlib.h>

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long* prefixSum = (long*)malloc((numsSize + 1) * sizeof(long));
    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    int count = countWhileMergeSort(prefixSum, 0, numsSize, lower, upper);
    free(prefixSum);
    return count;
}

int countWhileMergeSort(long* prefixSum, int start, int end, int lower, int upper) {
    if (end <= start) {
        return 0;
    }
    int mid = start + (end - start) / 2;
    int count = countWhileMergeSort(prefixSum, start, mid, lower, upper) + countWhileMergeSort(prefixSum, mid + 1, end, lower, upper);
    int j = mid + 1, k = mid + 1, lowerBound = mid + 1, upperBound = mid + 1;
    long* cache = (long*)malloc((end - start + 1) * sizeof(long));
    int idx = 0;
    for (int i = start; i <= mid; i++) {
        while (j <= end && prefixSum[j] - prefixSum[i] < lower) {
            j++;
        }
        while (k <= end && prefixSum[k] - prefixSum[i] <= upper) {
            k++;
        }
        count += k - j;
        while (lowerBound <= end && prefixSum[lowerBound] <= prefixSum[i]) {
            lowerBound++;
        }
        while (upperBound <= end && prefixSum[upperBound] < prefixSum[i]) {
            upperBound++;
        }
        count -= upperBound - lowerBound;
        while (start + idx <= mid && prefixSum[start + idx] <= prefixSum[i]) {
            cache[idx++] = prefixSum[start + idx];
        }
    }
    for (int i = start + idx; i <= mid; i++) {
        cache[idx++] = prefixSum[i];
    }
    for (int i = start; i <= mid; i++) {
        prefixSum[i] = cache[i - start];
    }
    free(cache);
    return count;
}
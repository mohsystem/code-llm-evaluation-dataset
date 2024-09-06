
#include <stdlib.h>

int merge(long long* arr, int left, int mid, int right, int lower, int upper) {
    int count = 0;
    int j = mid + 1, k = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && arr[j] - arr[i] < lower) j++;
        while (k <= right && arr[k] - arr[i] <= upper) k++;
        count += k - j;
    }

    long long* temp = (long long*)malloc((right - left + 1) * sizeof(long long));
    int i = left, m = mid + 1, t = 0;
    while (i <= mid && m <= right) {
        if (arr[i] <= arr[m]) temp[t++] = arr[i++];
        else temp[t++] = arr[m++];
    }
    while (i <= mid) temp[t++] = arr[i++];
    while (m <= right) temp[t++] = arr[m++];
    for (i = 0; i < right - left + 1; i++) arr[left + i] = temp[i];
    free(temp);
    return count;
}

int mergeSort(long long* arr, int left, int right, int lower, int upper) {
    if (left >= right) return 0;
    int mid = (left + right) / 2;
    int count = mergeSort(arr, left, mid, lower, upper) + mergeSort(arr, mid + 1, right, lower, upper);
    return count + merge(arr, left, mid, right, lower, upper);
}

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    long long* prefixSum = (long long*)malloc((numsSize + 1) * sizeof(long long));
    prefixSum[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }
    int result = mergeSort(prefixSum, 0, numsSize, lower, upper);
    free(prefixSum);
    return result;
}

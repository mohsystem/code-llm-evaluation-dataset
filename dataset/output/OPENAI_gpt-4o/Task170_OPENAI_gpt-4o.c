#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

int count;

void mergeSort(lli* sums, int lo, int hi, int lower, int upper);

int countRangeSum(int* nums, int numsSize, int lower, int upper) {
    count = 0;
    lli* sums = (lli*)malloc((numsSize + 1) * sizeof(lli));
    sums[0] = 0;
    for (int i = 0; i < numsSize; ++i) {
        sums[i + 1] = sums[i] + nums[i];
    }
    mergeSort(sums, 0, numsSize, lower, upper);
    free(sums);
    return count;
}

void mergeSort(lli* sums, int lo, int hi, int lower, int upper) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSort(sums, lo, mid, lower, upper);
    mergeSort(sums, mid + 1, hi, lower, upper);

    int i = lo, m = mid + 1, n = mid + 1;
    while (i <= mid) {
        while (m <= hi && sums[m] - sums[i] < lower) m++;
        while (n <= hi && sums[n] - sums[i] <= upper) n++;
        count += n - m;
        i++;
    }

    lli* temp = (lli*)malloc((hi - lo + 1) * sizeof(lli));
    int k = 0, j = mid + 1;
    i = lo;
    while (i <= mid && j <= hi) {
        if (sums[i] < sums[j]) {
            temp[k++] = sums[i++];
        } else {
            temp[k++] = sums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = sums[i++];
    }
    while (j <= hi) {
        temp[k++] = sums[j++];
    }
    for (i = lo, k = 0; i <= hi; ++i, ++k) {
        sums[i] = temp[k];
    }
    free(temp);
}

int main() {
    int nums[] = {-2, 5, -1};
    int lower = -2, upper = 2;
    int result = countRangeSum(nums, 3, lower, upper);
    printf("%d\n", result);  // Output: 3
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int merge(int* nums, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int count = 0;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    j = 0;
    for (i = 0; i < n1; i++) {
        while (j < n2 && L[i] > 2LL * R[j]) {
            j++;
        }
        count += j;
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

    return count;
}

int mergeSort(int* nums, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSort(nums, left, mid);
        count += mergeSort(nums, mid + 1, right);
        count += merge(nums, left, mid, right);
    }
    return count;
}

int reversePairs(int* nums, int numsSize) {
    return mergeSort(nums, 0, numsSize - 1);
}

int main() {
    int nums1[] = {1, 3, 2, 3, 1};
    int nums2[] = {2, 4, 3, 5, 1};
    printf("%d\\n", reversePairs(nums1, 5));  // Output: 2
    printf("%d\\n", reversePairs(nums2, 5));  // Output: 3
    return 0;
}

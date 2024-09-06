#include <stdio.h>
#include <string.h>

int merge_sort(int* nums, int start, int end, int* temp) {
    if (end - start <= 1) {
        return 0;
    }

    int mid = (start + end) / 2;
    int count = 0;

    count += merge_sort(nums, start, mid, temp);
    count += merge_sort(nums, mid, end, temp);
    
    int j = mid;
    for (int i = start; i < mid; i++) {
        while (j < end && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += j - mid;
    }
    
    int l = start, r = mid, k = start;
    while (l < mid && r < end) {
        if (nums[l] <= nums[r]) {
            temp[k++] = nums[l++];
        } else {
            temp[k++] = nums[r++];
        }
    }
    while (l < mid) {
        temp[k++] = nums[l++];
    }
    while (r < end) {
        temp[k++] = nums[r++];
    }
    
    memcpy(nums + start, temp + start, (end - start) * sizeof(int));
    
    return count;
}

int reversePairs(int* nums, int numsSize) {
    int* temp = (int*)malloc(numsSize * sizeof(int));
    int count = merge_sort(nums, 0, numsSize, temp);
    free(temp);
    return count;
}

int main() {
    int nums1[] = {1, 3, 2, 3, 1};
    int numsSize1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("%d\n", reversePairs(nums1, numsSize1));  // Output: 2

    int nums2[] = {2, 4, 3, 5, 1};
    int numsSize2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("%d\n", reversePairs(nums2, numsSize2));  // Output: 3

    return 0;
}
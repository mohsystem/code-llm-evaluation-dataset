#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    std::multiset<int> sortedSet;
    for (int i = numsSize - 1; i >= 0; i--) {
        auto it = sortedSet.upper_bound(nums[i]);
        int index = std::distance(sortedSet.begin(), it);
        result[i] = index;
        sortedSet.insert(nums[i]);
    }
    *returnSize = numsSize;
    return result;
}
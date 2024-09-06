
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int findKthLargest(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    return nums[k-1];
}

int main() {
    int numsSize;
    printf("Enter the number of elements: ");
    scanf("%d", &numsSize);
    
    int* nums = (int*)malloc(numsSize * sizeof(int));
    printf("Enter the array elements:\\n");
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }
    
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    printf("The %dth largest element is: %d\\n", k, findKthLargest(nums, numsSize, k));
    
    free(nums);
    return 0;
}

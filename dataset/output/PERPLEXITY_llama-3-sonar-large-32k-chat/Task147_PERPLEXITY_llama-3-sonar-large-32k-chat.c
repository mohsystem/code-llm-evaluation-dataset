#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *nums = (int*)malloc(n * sizeof(int));
    printf("Enter the array of integers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    qsort(nums, n, sizeof(int), compare);
    printf("The kth largest element is: %d\n", nums[k-1]);
    free(nums);
    return 0;
}

int merge(int* nums, int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int count = 0;
    int* temp = (int*)malloc((right - left + 1) * sizeof(int));
    
    while (i <= mid && j <= right) {
        if ((long long)nums[i] <= 2LL * nums[j]) {
            temp[k++] = nums[i++];
        } else {
            count += mid - i + 1;
            temp[k++] = nums[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    
    for (i = 0; i < k; i++) {
        nums[left + i] = temp[i];
    }
    
    free(temp);
    return count;
}

int mergeSort(int* nums, int left, int right) {
    if (left >= right) {
        return 0;
    }
    
    int mid = left + (right - left) / 2;
    int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
    
    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += j - (mid + 1);
    }
    
    return count + merge(nums, left, mid, right);
}

int reversePairs(int* nums, int numsSize) {
    return mergeSort(nums, 0, numsSize - 1);
}

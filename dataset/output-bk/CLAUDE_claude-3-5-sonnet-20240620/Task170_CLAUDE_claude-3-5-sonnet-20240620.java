
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        long[] prefixSum = new long[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return mergeSort(prefixSum, 0, prefixSum.length - 1, lower, upper);
    }
    
    private int mergeSort(long[] arr, int left, int right, int lower, int upper) {
        if (left >= right) {
            return 0;
        }
        
        int mid = (left + right) / 2;
        int count = mergeSort(arr, left, mid, lower, upper) + mergeSort(arr, mid + 1, right, lower, upper);
        
        int j = mid + 1, k = mid + 1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && arr[j] - arr[i] < lower) {
                j++;
            }
            while (k <= right && arr[k] - arr[i] <= upper) {
                k++;
            }
            count += k - j;
        }
        
        merge(arr, left, mid, right);
        return count;
    }
    
    private void merge(long[] arr, int left, int mid, int right) {
        long[] temp = new long[right - left + 1];
        int i = left, j = mid + 1, k = 0;
        
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        
        while (j <= right) {
            temp[k++] = arr[j++];
        }
        
        System.arraycopy(temp, 0, arr, left, temp.length);
    }
}

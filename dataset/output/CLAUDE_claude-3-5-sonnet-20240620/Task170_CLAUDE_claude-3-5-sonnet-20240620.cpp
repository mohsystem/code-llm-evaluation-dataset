
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefixSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return mergeSort(prefixSum, 0, prefixSum.size() - 1, lower, upper);
    }
    
private:
    int mergeSort(vector<long long>& arr, int left, int right, int lower, int upper) {
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
        
        inplace_merge(arr.begin() + left, arr.begin() + mid + 1, arr.begin() + right + 1);
        return count;
    }
};

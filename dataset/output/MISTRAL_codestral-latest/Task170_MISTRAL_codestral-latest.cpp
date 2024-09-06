// C++ code
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> prefixSum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return countWhileMergeSort(prefixSum, 0, prefixSum.size() - 1, lower, upper);
    }

private:
    int countWhileMergeSort(vector<long>& prefixSum, int start, int end, int lower, int upper) {
        if (end <= start) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int count = countWhileMergeSort(prefixSum, start, mid, lower, upper) + countWhileMergeSort(prefixSum, mid + 1, end, lower, upper);
        int j = mid + 1, k = mid + 1, lowerBound = mid + 1, upperBound = mid + 1;
        vector<long> cache(end - start + 1);
        int idx = 0;
        for (int i = start; i <= mid; i++) {
            while (j <= end && prefixSum[j] - prefixSum[i] < lower) {
                j++;
            }
            while (k <= end && prefixSum[k] - prefixSum[i] <= upper) {
                k++;
            }
            count += k - j;
            while (lowerBound <= end && prefixSum[lowerBound] <= prefixSum[i]) {
                lowerBound++;
            }
            while (upperBound <= end && prefixSum[upperBound] < prefixSum[i]) {
                upperBound++;
            }
            count -= upperBound - lowerBound;
            while (start + idx <= mid && prefixSum[start + idx] <= prefixSum[i]) {
                cache[idx++] = prefixSum[start + idx];
            }
        }
        copy(prefixSum.begin() + start + idx, prefixSum.begin() + mid + 1, cache.begin() + idx);
        copy(cache.begin(), cache.begin() + mid - start + 1, prefixSum.begin() + start);
        return count;
    }
};
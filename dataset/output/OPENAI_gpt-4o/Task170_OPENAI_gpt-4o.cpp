#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countRangeSum(std::vector<int>& nums, int lower, int upper) {
        int count = 0;
        std::vector<long> sums(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i] + nums[i];
        }
        mergeSort(sums, 0, sums.size() - 1, lower, upper, count);
        return count;
    }

private:
    void mergeSort(std::vector<long>& sums, int lo, int hi, int lower, int upper, int& count) {
        if (lo >= hi) return;
        int mid = (lo + hi) / 2;
        mergeSort(sums, lo, mid, lower, upper, count);
        mergeSort(sums, mid + 1, hi, lower, upper, count);

        int i = lo, j = mid + 1, m = mid + 1, n = mid + 1;
        while (i <= mid) {
            while (m <= hi && sums[m] - sums[i] < lower) m++;
            while (n <= hi && sums[n] - sums[i] <= upper) n++;
            count += n - m;
            while (j <= hi && sums[j] < sums[i]) j++;
            i++;
        }
        std::inplace_merge(sums.begin() + lo, sums.begin() + mid + 1, sums.begin() + hi + 1);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {-2, 5, -1};
    int lower = -2, upper = 2;
    std::cout << sol.countRangeSum(nums, lower, upper) << std::endl;  // Output: 3
    return 0;
}
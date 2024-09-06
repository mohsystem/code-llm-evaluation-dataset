#include <vector>
#include <algorithm>
#include <iostream>

class MedianFinder {
public:
    std::vector<int> nums;

    MedianFinder() {}

    void addNum(int num) {
        auto it = std::lower_bound(nums.begin(), nums.end(), num);
        nums.insert(it, num);
    }

    double findMedian() {
        int n = nums.size();
        if (n % 2 == 1) {
            return nums[n / 2];
        } else {
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }
    }
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    std::cout << medianFinder.findMedian() << std::endl; // 1.5
    medianFinder.addNum(3);
    std::cout << medianFinder.findMedian() << std::endl; // 2.0
}
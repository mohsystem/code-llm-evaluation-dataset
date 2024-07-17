
#include <iostream>
#include <vector>
#include <algorithm>

int findKthLargest(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    return nums[k-1];
}

int main() {
    std::vector<int> nums;
    int n, num, k;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the array elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> num;
        nums.push_back(num);
    }

    std::cout << "Enter the value of k: ";
    std::cin >> k;

    int result = findKthLargest(nums, k);
    std::cout << "The " << k << "th largest element is: " << result << std::endl;

    return 0;
}

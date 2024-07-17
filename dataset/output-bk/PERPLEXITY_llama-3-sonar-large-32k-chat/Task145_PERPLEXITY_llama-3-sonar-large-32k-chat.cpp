#include <iostream>
#include <vector>
#include <algorithm>

int maxSubarraySum(std::vector<int>& arr) {
    int maxSum = INT_MIN;
    int currentSum = 0;
    for (int num : arr) {
        currentSum = std::max(num, currentSum + num);
        maxSum = std::max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    std::vector<int> arr;
    int num;
    std::cout << "Enter the array elements separated by space: ";
    while (std::cin >> num) {
        arr.push_back(num);
        if (std::cin.peek() == '
') break;
    }
    std::cout << "Maximum contiguous sum is " << maxSubarraySum(arr) << std::endl;
    return 0;
}
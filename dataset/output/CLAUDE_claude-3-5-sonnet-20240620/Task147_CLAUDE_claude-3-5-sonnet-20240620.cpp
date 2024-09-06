
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

int findKthLargest(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());
    return nums[k-1];
}

int main() {
    std::string input;
    std::cout << "Enter the array elements separated by space: ";
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<int> nums;
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }
    
    int k;
    std::cout << "Enter the value of k: ";
    std::cin >> k;
    
    std::cout << "The " << k << "th largest element is: " << findKthLargest(nums, k) << std::endl;
    return 0;
}

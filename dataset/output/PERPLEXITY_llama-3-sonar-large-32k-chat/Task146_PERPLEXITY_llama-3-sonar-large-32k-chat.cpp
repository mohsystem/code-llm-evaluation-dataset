#include <iostream>
#include <vector>
#include <algorithm>

int find_missing_number(std::vector<int>& nums) {
    int n = nums.size() + 1;
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return total - sum;
}

int main() {
    std::vector<int> nums;
    int num;
    std::cout << "Enter the array of unique integers: ";
    while (std::cin >> num) {
        nums.push_back(num);
        if (std::cin.peek() == '
') break;
    }
    std::cout << "The missing number is: " << find_missing_number(nums) << std::endl;
    return 0;
}
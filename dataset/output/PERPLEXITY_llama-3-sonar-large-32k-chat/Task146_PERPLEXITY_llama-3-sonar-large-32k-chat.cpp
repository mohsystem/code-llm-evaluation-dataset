#include <iostream>
#include <vector>

int find_missing_number(std::vector<int>& nums) {
    int n = nums.size() + 1;
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int num : nums) {
        actual_sum += num;
    }
    return expected_sum - actual_sum;
}

int main() {
    std::vector<int> nums;
    int num;
    std::cout << "Enter the array of numbers: ";
    while (std::cin >> num) {
        nums.push_back(num);
        if (std::cin.peek() == '\n') break;
    }
    int missing_number = find_missing_number(nums);
    std::cout << "The missing number is: " << missing_number << std::endl;
    return 0;
}
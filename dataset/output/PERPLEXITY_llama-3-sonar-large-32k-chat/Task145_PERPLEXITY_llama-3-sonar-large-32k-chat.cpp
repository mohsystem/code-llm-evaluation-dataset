#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArraySum(std::vector<int>& arr) {
    int maxCurrent = maxGlobal = arr[0];
    for (int i =  = 1; i < arr.size(); i++) {
        maxCurrent = std::max(arr[i], maxCurrent + arr[i]);
        if (maxCurrent > maxGlobal) {
            maxGlobal = maxCurrent;
        }
    }
    return maxGlobal;
}

int main() {
    std::vector<int> arr;
    int num;
    std::cout << "Enter the array elements separated by space: ";
    while (std::cin >> num) {
        arr.push_back(num);
        if (std::cin.peek() == '\n') {
            break;
        }
    }
    std::cout << "Maximum contiguous sum is " << maxSubArraySum(arr) << std::endl;
    return 0;
}
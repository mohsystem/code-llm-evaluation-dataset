
#include <iostream>
#include <vector>
#include <algorithm>

int findOutlier(std::vector<int> arr) {
    std::vector<int> evens, odds;
    for (int num : arr) {
        if (num % 2 == 0) evens.push_back(num);
        else odds.push_back(num);
    }
    return evens.size() == 1 ? evens[0] : odds[0];
}

int main() {
    std::cout << findOutlier({2, 4, 0, 100, 4, 11, 2602, 36}) << std::endl;  // Output: 11
    std::cout << findOutlier({160, 3, 1719, 19, 11, 13, -21}) << std::endl;  // Output: 160
    return 0;
}

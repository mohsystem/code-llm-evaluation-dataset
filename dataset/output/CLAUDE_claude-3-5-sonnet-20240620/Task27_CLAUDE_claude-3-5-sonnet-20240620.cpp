
#include <iostream>
#include <vector>
#include <algorithm>

int findOutlier(std::vector<int> arr) {
    std::vector<int> odds, evens;
    
    for (int num : arr) {
        if (num % 2 == 0) {
            evens.push_back(num);
        } else {
            odds.push_back(num);
        }
    }
    
    return odds.size() == 1 ? odds[0] : evens[0];
}

int main() {
    std::cout << findOutlier({2, 4, 0, 100, 4, 11, 2602, 36}) << std::endl;
    std::cout << findOutlier({160, 3, 1719, 19, 11, 13, -21}) << std::endl;
    return 0;
}

#include <iostream>
#include <vector>

int findOutlier(const std::vector<int>& integers) {
    std::vector<int> odds;
    std::vector<int> evens;

    for (int i : integers) {
        if (i % 2 == 0) {
            evens.push_back(i);
        } else {
            odds.push_back(i);
        }
    }

    return odds.size() == 1 ? odds[0] : evens[0];
}

int main() {
    std::vector<int> vec1 = {2, 4, 0, 100, 4, 11, 2602, 36};
    std::vector<int> vec2 = {160, 3, 1719, 19, 11, 13, -21};

    std::cout << findOutlier(vec1) << std::endl;  // Output: 11
    std::cout << findOutlier(vec2) << std::endl;  // Output: 160

    return 0;
}
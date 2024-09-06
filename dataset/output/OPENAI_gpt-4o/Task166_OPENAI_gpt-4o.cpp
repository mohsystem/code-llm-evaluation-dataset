#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> posNegSort(const std::vector<int>& lst) {
    std::vector<int> pos_nums;
    for (int num : lst) {
        if (num > 0) pos_nums.push_back(num);
    }
    std::sort(pos_nums.begin(), pos_nums.end());
    
    std::vector<int> result;
    int pos_index = 0;
    for (int num : lst) {
        if (num > 0) {
            result.push_back(pos_nums[pos_index++]);
        } else {
            result.push_back(num);
        }
    }
    return result;
}

void printVector(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    printVector(posNegSort({6, 3, -2, 5, -8, 2, -2}));  // [2, 3, -2, 5, -8, 6, -2]
    printVector(posNegSort({6, 5, 4, -1, 3, 2, -1, 1}));  // [1, 2, 3, -1, 4, 5, -1, 6]
    printVector(posNegSort({-5, -5, -5, -5, 7, -5}));  // [-5, -5, -5, -5, 7, -5]
    printVector(posNegSort({}));  // []
    return 0;
}
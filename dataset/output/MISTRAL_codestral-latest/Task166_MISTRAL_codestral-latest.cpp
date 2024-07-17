#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> posNegSort(std::vector<int> arr) {
    std::vector<int> pos;
    std::vector<int> neg;
    std::vector<int> result;

    for (int num : arr) {
        if (num > 0) {
            pos.push_back(num);
        } else {
            neg.push_back(num);
        }
    }

    std::sort(pos.begin(), pos.end());

    for (int num : arr) {
        if (num > 0) {
            result.push_back(pos.front());
            pos.erase(pos.begin());
        } else {
            result.push_back(num);
        }
    }

    return result;
}

int main() {
    std::vector<int> arr = {6, 3, -2, 5, -8, 2, -2};
    std::vector<int> result = posNegSort(arr);
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> posNegSort(std::vector<int> arr) {
    std::vector<int> pos;
    for (int x : arr) {
        if (x > 0) {
            pos.push_back(x);
        }
    }
    std::sort(pos.begin(), pos.end());
    int pos_index = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            arr[i] = pos[pos_index];
            pos_index++;
        }
    }
    return arr;
}

int main() {
    std::vector<int> arr = {6, 3, -2, 5, -8, 2, -2};
    arr = posNegSort(arr);
    for (int x : arr) {
        std::cout << x << " ";
    }
    return 0;
}
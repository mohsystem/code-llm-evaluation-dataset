#include <vector>
#include <algorithm>

std::vector<int> posNegSort(std::vector<int>& arr) {
    std::vector<int> pos;
    for (int num : arr) {
        if (num > 0) {
            pos.push_back(num);
        }
    }
    std::sort(pos.begin(), pos.end());
    int pos_i = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            arr[i] = pos[pos_i];
            pos_i += 1;
        }
    }
    return arr;
}
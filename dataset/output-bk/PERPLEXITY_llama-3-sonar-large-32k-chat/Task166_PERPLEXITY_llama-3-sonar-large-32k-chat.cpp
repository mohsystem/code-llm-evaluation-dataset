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
    std::vector<int> res;
    int pos_index = 0;
    for (int x : arr) {
        if (x > 0) {
            res.push_back(pos[pos_index]);
            pos_index++;
        } else {
            res.push_back(x);
        }
    }
    return res;
}
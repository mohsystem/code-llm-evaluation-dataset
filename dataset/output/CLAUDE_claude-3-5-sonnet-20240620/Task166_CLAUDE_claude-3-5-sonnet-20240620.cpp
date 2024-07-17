
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> posNegSort(std::vector<int>& arr) {
        std::vector<int> pos;
        for (int num : arr) {
            if (num > 0) {
                pos.push_back(num);
            }
        }
        std::sort(pos.begin(), pos.end());
        
        std::vector<int> result;
        int posIndex = 0;
        for (int num : arr) {
            if (num > 0) {
                result.push_back(pos[posIndex++]);
            } else {
                result.push_back(num);
            }
        }
        return result;
    }
};

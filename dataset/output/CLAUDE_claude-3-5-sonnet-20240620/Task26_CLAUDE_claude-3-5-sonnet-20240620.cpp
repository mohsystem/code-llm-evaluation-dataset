
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findOddOccurrence(std::vector<int>& arr) {
        std::unordered_map<int, int> countMap;
        
        for (int num : arr) {
            countMap[num]++;
        }
        
        for (const auto& pair : countMap) {
            if (pair.second % 2 != 0) {
                return pair.first;
            }
        }
        
        return -1; // This line should never be reached given the problem constraints
    }
};

int main() {
    Solution solution;
    std::vector<int> arr1 = {7};
    std::vector<int> arr2 = {0};
    std::vector<int> arr3 = {1,1,2};
    std::vector<int> arr4 = {0,1,0,1,0};
    std::vector<int> arr5 = {1,2,2,3,3,3,4,3,3,3,2,2,1};

    std::cout << solution.findOddOccurrence(arr1) << std::endl;
    std::cout << solution.findOddOccurrence(arr2) << std::endl;
    std::cout << solution.findOddOccurrence(arr3) << std::endl;
    std::cout << solution.findOddOccurrence(arr4) << std::endl;
    std::cout << solution.findOddOccurrence(arr5) << std::endl;

    return 0;
}


#include <vector>
#include <numeric>

class Solution {
public:
    int findEvenIndex(const std::vector<int>& arr) {
        int leftSum = 0;
        int rightSum = std::accumulate(arr.begin(), arr.end(), 0);
        
        for (int i = 0; i < arr.size(); i++) {
            rightSum -= arr[i];
            
            if (leftSum == rightSum) {
                return i;
            }
            
            leftSum += arr[i];
        }
        
        return -1;
    }
};

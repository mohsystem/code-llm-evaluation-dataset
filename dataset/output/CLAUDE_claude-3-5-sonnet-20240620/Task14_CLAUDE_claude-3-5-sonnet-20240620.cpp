
#include <iostream>
#include <vector>

class Solution {
public:
    static int findEvenIndex(const std::vector<int>& arr) {
        int leftSum = 0;
        int rightSum = 0;
        
        for (int num : arr) {
            rightSum += num;
        }
        
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

int main() {
    std::vector<int> arr1 = {1,2,3,4,3,2,1};
    std::vector<int> arr2 = {1,100,50,-51,1,1};
    std::vector<int> arr3 = {20,10,-80,10,10,15,35};
    
    std::cout << Solution::findEvenIndex(arr1) << std::endl;
    std::cout << Solution::findEvenIndex(arr2) << std::endl;
    std::cout << Solution::findEvenIndex(arr3) << std::endl;
    
    return 0;
}

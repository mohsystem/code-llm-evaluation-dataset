#include <iostream>
#include <vector>

int findOutlier(const std::vector<int>& arr) {
    int oddCount = 0, evenCount = 0, oddNum = 0, evenNum = 0;
    for (int i = 0; i < arr.size() && (oddCount == 0 || evenCount == 0); ++i) {
        if (arr[i] % 2 == 0) {
            evenCount++;
            evenNum = arr[i];
        } else {
            oddCount++;
            oddNum = arr[i];
        }
    }
    return oddCount == 1 ? oddNum : evenNum;
}

int main() {
    std::vector<int> example1 = {2, 4, 0, 100, 4, 11, 2602, 36};
    std::vector<int> example2 = {160, 3, 1719, 19, 11, 13, -21};
    std::cout << findOutlier(example1) << std::endl;  // Should print 11
    std::cout << findOutlier(example2) << std::endl;  // Should print 160
    return 0;
}
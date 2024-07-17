
#include <iostream>
#include <algorithm>

class Solution {
public:
    static int getSum(int a, int b) {
        if (a == b) {
            return a;
        }
        int start = std::min(a, b);
        int end = std::max(a, b);
        int sum = 0;
        for (int i = start; i <= end; i++) {
            sum += i;
        }
        return sum;
    }
};

int main() {
    std::cout << Solution::getSum(1, 0) << std::endl;
    std::cout << Solution::getSum(1, 2) << std::endl;
    std::cout << Solution::getSum(0, 1) << std::endl;
    std::cout << Solution::getSum(1, 1) << std::endl;
    std::cout << Solution::getSum(-1, 0) << std::endl;
    std::cout << Solution::getSum(-1, 2) << std::endl;
    return 0;
}

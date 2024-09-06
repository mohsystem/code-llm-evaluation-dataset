
class Solution {
public:
    int getSum(int a, int b) {
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

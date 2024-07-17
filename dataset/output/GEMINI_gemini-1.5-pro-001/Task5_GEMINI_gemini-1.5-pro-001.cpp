class Solution {
public:
    int persistence(long long n) {
        if (n < 10) {
            return 0;
        }
        int count = 0;
        long long temp = 1;
        while (n >= 10) {
            while (n > 0) {
                temp *= n % 10;
                n /= 10;
            }
            n = temp;
            temp = 1;
            count++;
        }
        return count;
    }
};
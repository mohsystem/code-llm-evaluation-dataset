
#include <cmath>
#include <string>

class DigPow {
public:
    static long long digPow(int n, int p) {
        long long sum = 0;
        std::string num = std::to_string(n);
        for (char c : num) {
            sum += std::pow(c - '0', p++);
        }
        return sum % n == 0 ? sum / n : -1;
    }
};

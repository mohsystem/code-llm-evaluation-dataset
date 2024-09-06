#include <cmath>
#include <string>

int dig_pow(int n, int p) {
    std::string s = std::to_string(n);
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += std::pow(s[i] - '0', p + i);
    }
    return sum % n == 0 ? sum / n : -1;
}
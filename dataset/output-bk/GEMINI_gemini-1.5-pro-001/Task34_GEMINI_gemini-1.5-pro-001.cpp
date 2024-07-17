#include <cmath>

class Solution {
public:
    static bool isNarcissistic(int number) {
        if (number < 0) {
            return false;
        }
        int originalNumber = number;
        int sum = 0;
        int digits = std::to_string(number).length();
        while (number > 0) {
            int digit = number % 10;
            sum += std::pow(digit, digits);
            number /= 10;
        }
        return sum == originalNumber;
    }
};
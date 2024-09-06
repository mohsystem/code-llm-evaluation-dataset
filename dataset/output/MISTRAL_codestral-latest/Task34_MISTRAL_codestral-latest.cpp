#include <cmath>
#include <string>

bool narcissistic(int value) {
    std::string str_value = std::to_string(value);
    int n = str_value.length();
    int sum = 0;

    for (char c : str_value) {
        sum += std::pow(c - '0', n);
    }

    return value == sum;
}
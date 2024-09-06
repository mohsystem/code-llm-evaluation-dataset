#include <cmath>
#include <string>

bool narcissistic(int value) {
    int sum = 0;
    std::string strValue = std::to_string(value);
    for (char digit : strValue) {
        sum += pow(std::stoi(std::string(1, digit)), strValue.length());
    }
    return value == sum;
}

#include <iostream>
#include <cmath>
#include <string>

bool narcissistic(int num) {
    std::string numStr = std::to_string(num);
    int power = numStr.length();
    int sum = 0;
    
    for (char digit : numStr) {
        sum += std::pow(digit - '0', power);
    }
    
    return sum == num;
}

int main() {
    std::cout << std::boolalpha;
    std::cout << narcissistic(153) << std::endl;  // true
    std::cout << narcissistic(1652) << std::endl;  // false
    return 0;
}

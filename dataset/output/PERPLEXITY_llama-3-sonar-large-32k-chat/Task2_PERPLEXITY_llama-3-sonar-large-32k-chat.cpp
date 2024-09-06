#include <string>
#include <iostream>

std::string createPhoneNumber(int numbers[10]) {
    return std::string("(") + std::to_string(numbers[0]) + std::to_string(numbers[1]) + std::to_string(numbers[2]) + ") " + 
           std::to_string(numbers[3]) + std::to_string(numbers[4]) + std::to_string(numbers[5]) + "-" + 
           std::to_string(numbers[6]) + std::to_string(numbers[7]) + std::to_string(numbers[8]) + std::to_string(numbers[9]);
}
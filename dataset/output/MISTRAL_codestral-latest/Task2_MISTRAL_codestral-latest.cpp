#include <iostream>
#include <cstdio>

std::string createPhoneNumber(int numbers[10]) {
    char phoneNumber[15];
    sprintf(phoneNumber, "(%d%d%d) %d%d%d-%d%d%d%d", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);
    return std::string(phoneNumber);
}
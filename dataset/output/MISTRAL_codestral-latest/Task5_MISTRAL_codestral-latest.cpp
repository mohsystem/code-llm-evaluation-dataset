#include <string>
#include <iostream>

int persistence(int num) {
    int count = 0;
    while (num >= 10) {
        int product = 1;
        std::string strNum = std::to_string(num);
        for (char c : strNum) {
            product *= c - '0';
        }
        num = product;
        count++;
    }
    return count;
}
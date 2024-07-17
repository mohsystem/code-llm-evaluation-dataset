#include <iostream>
#include <string>
#include <sstream>

std::string createPhoneNumber(int numbers[]) {
    std::stringstream ss;
    ss << "(" << numbers[0] << numbers[1] << numbers[2] << ") " << numbers[3] << numbers[4] << numbers[5] << "-" << numbers[6] << numbers[7] << numbers[8] << numbers[9];
    return ss.str();
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << createPhoneNumber(numbers) << std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <iomanip>

std::string createPhoneNumber(int arr[10]) {
    char buffer[15];
    snprintf(buffer, sizeof(buffer), "(%d%d%d) %d%d%d-%d%d%d%d", 
             arr[0], arr[1], arr[2], 
             arr[3], arr[4], arr[5], 
             arr[6], arr[7], arr[8], 
             arr[9]);
    return std::string(buffer);
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << createPhoneNumber(arr) << std::endl;
    return 0;
}
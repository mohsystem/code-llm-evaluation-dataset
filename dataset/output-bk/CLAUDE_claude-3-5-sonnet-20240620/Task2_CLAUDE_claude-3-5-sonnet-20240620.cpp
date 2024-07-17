
#include <iostream>
#include <string>

std::string createPhoneNumber(const int arr[10]) {
    char phone_number[15];
    sprintf(phone_number, "(%d%d%d) %d%d%d-%d%d%d%d",
        arr[0], arr[1], arr[2], arr[3], arr[4],
        arr[5], arr[6], arr[7], arr[8], arr[9]);
    return std::string(phone_number);
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::cout << createPhoneNumber(numbers) << std::endl;
    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomNumber() {
    return rand() % 100 + 1;
}

int main() {
    srand(time(0));
    std::cout << "C++ random number: " << generateRandomNumber() << std::endl;
    return 0;
}
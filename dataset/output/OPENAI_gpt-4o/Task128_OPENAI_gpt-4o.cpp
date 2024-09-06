#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    std::cout << "CPP Random Number: " << std::rand() % 100 + 1 << std::endl;
    return 0;
}
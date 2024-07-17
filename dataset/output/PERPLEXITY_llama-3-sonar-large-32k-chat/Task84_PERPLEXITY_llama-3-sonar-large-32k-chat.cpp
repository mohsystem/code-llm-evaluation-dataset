#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int sessionId = rand();
    std::cout << "Session ID: " << sessionId << std::endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>

int main() {
    std::ofstream logFile("security.log", std::ios::app);

    while (true) {
        time_t now = time(0);
        char* dt = ctime(&now);
        std::string event = "Security event detected at " + std::string(dt);
        logFile << event << std::endl;
        sleep(5);
    }

    logFile.close();
    return 0;
}
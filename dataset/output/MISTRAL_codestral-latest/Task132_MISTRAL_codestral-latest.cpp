#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

int main() {
    std::ofstream logFile("security.log", std::ios::app);

    while (true) {
        // Simulate a security event
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        logFile << "Security event detected at " << std::ctime(&time) << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    logFile.close();
    return 0;
}
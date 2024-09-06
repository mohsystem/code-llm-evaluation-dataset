#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void logEvent(const std::string& event) {
    std::ofstream logFile("security_log.txt", std::ios::app);
    if (logFile.is_open()) {
        time_t now = time(0);
        logFile << ctime(&now) << " - " << event << std::endl;
        logFile.close();
    } else {
        std::cerr << "Error writing to log file." << std::endl;
    }
}

void monitorEvents() {
    std::string event;
    while (true) {
        std::cout << "Enter an event (or 'quit' to exit): ";
        std::getline(std::cin, event);
        if (event == "quit") {
            break;
        }
        logEvent(event);
    }
}

int main() {
    monitorEvents();
    return 0;
}
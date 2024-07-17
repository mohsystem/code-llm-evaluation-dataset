
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

void logEvent(const std::string& eventType, const std::string& description) {
    std::ofstream logFile("security_events.log", std::ios::app);
    if (logFile.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        logFile << dt << "Event Type: " << eventType << ", Description: " << description << std::endl;
        logFile.close();
    } else {
        std::cerr << "Unable to open log file!" << std::endl;
    }
}

void monitorEvents() {
    std::string eventType, description;
    while (true) {
        std::cout << "Enter event type (or \'q\' to quit): ";
        std::getline(std::cin, eventType);
        if (eventType == "q" || eventType == "Q") {
            break;
        }
        std::cout << "Enter event description: ";
        std::getline(std::cin, description);
        logEvent(eventType, description);
    }
}

int main() {
    std::cout << "Security Event Monitoring System" << std::endl;
    monitorEvents();
    return 0;
}

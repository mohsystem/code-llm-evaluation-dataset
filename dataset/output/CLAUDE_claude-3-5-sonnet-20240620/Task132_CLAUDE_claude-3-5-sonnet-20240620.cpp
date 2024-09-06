
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <string>

void logEvent(const std::string& eventType, const std::string& description) {
    std::ofstream logFile("security_events.log", std::ios::app);
    if (logFile.is_open()) {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        logFile << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X") 
                << " - INFO - Event Type: " << eventType 
                << ", Description: " << description << std::endl;
        logFile.close();
    } else {
        std::cerr << "Unable to open log file!" << std::endl;
    }
}

int main() {
    std::cout << "Security Event Monitoring System" << std::endl;

    std::string eventType, description;
    while (true) {
        std::cout << "Enter event type (or 'q' to quit): ";
        std::getline(std::cin, eventType);
        if (eventType == "q" || eventType == "Q") {
            break;
        }

        std::cout << "Enter event description: ";
        std::getline(std::cin, description);

        logEvent(eventType, description);
        std::cout << "Event logged successfully." << std::endl;
    }

    std::cout << "Monitoring ended. Check 'security_events.log' for recorded events." << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <thread>

class SecurityEventLogger {
private:
    std::vector<std::string> events;

    std::string currentDateTime() {
        auto now = std::chrono::system_clock::now();
        std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        char timestamp[20];
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime));
        return std::string(timestamp);
    }

public:
    void logEvent(const std::string& event) {
        events.push_back(currentDateTime() + " - " + event);
    }

    void showEvents() const {
        for (const auto& event : events) {
            std::cout << event << std::endl;
        }
    }
};

int main() {
    SecurityEventLogger logger;
    logger.logEvent("User login");
    logger.logEvent("File accessed");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    logger.logEvent("User logout");
    logger.showEvents();
    return 0;
}
#include <iostream>
#include <vector>
#include <ctime>

class SecurityEvent {
public:
    std::string eventType;
    std::string description;
    time_t timestamp;

    SecurityEvent(std::string eventType, std::string description) {
        this->eventType = eventType;
        this->description = description;
        this->timestamp = time(0);
    }

    void logEvent() {
        std::cout << ctime(&timestamp) << " - " << eventType << ": " << description << std::endl;
    }
};

class SecurityMonitor {
private:
    std::vector<SecurityEvent> eventLog;

public:
    void logEvent(SecurityEvent event) {
        eventLog.push_back(event);
        event.logEvent();
    }

    void monitorEvents() {
        for (auto& event : eventLog) {
            std::cout << "Monitoring: " << event.eventType << " - " << event.description << std::endl;
        }
    }
};

int main() {
    SecurityMonitor monitor;
    monitor.logEvent(SecurityEvent("Login Attempt", "User attempted to login"));
    monitor.logEvent(SecurityEvent("File Access", "User accessed confidential file"));
    monitor.monitorEvents();
    return 0;
}
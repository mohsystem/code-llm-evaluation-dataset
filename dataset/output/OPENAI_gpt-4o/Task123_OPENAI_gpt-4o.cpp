#include <iostream>
#include <chrono>
#include <thread>

class UserSession {
    std::string userId;
    std::chrono::time_point<std::chrono::steady_clock> startTime;

public:
    UserSession(const std::string& userId) : userId(userId), startTime(std::chrono::steady_clock::now()) {}

    double getDuration() {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = currentTime - startTime;
        return duration.count();
    }

    std::string getUserId() {
        return userId;
    }
};

int main() {
    UserSession session("User1");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "CPP: Session duration for " << session.getUserId() << ": " << session.getDuration() << " seconds" << std::endl;
    return 0;
}
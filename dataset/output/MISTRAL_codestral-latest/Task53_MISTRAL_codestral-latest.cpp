// C++
#include <string>
#include <unordered_map>

class Session {
public:
    Session(const std::string& userId) : userId(userId), isActive(true) {}

    // Getters and setters for userId and isActive

private:
    std::string userId;
    bool isActive;
};

// Example usage:
int main() {
    std::unordered_map<std::string, Session> userSessions;
    std::string userId = "123";
    userSessions[userId] = Session(userId);
    return 0;
}
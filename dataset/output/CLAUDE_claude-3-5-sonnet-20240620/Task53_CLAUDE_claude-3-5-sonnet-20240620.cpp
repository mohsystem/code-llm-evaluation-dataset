
#include <iostream>
#include <unordered_map>
#include <string>
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>

class Session {
private:
    std::string sessionId;
    std::string userId;
    std::chrono::system_clock::time_point creationTime;
    std::chrono::system_clock::time_point lastAccessTime;

public:
    Session(const std::string& sessionId, const std::string& userId)
        : sessionId(sessionId), userId(userId), 
          creationTime(std::chrono::system_clock::now()),
          lastAccessTime(creationTime) {}

    const std::string& getSessionId() const { return sessionId; }
    const std::string& getUserId() const { return userId; }
    const std::chrono::system_clock::time_point& getCreationTime() const { return creationTime; }
    const std::chrono::system_clock::time_point& getLastAccessTime() const { return lastAccessTime; }
    void updateLastAccessTime() { lastAccessTime = std::chrono::system_clock::now(); }
};

class SessionManager {
private:
    std::unordered_map<std::string, Session> sessions;
    const std::chrono::minutes SESSION_TIMEOUT{30};

    std::string generateSessionId() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 15);
        
        std::stringstream ss;
        ss << std::hex;
        for (int i = 0; i < 32; i++) {
            ss << dis(gen);
        }
        return ss.str();
    }

public:
    std::string createSession(const std::string& userId) {
        std::string sessionId = generateSessionId();
        sessions.emplace(sessionId, Session(sessionId, userId));
        return sessionId;
    }

    bool validateSession(const std::string& sessionId) {
        auto it = sessions.find(sessionId);
        if (it != sessions.end()) {
            auto now = std::chrono::system_clock::now();
            if (now - it->second.getLastAccessTime() < SESSION_TIMEOUT) {
                it->second.updateLastAccessTime();
                return true;
            } else {
                sessions.erase(it);
            }
        }
        return false;
    }

    void endSession(const std::string& sessionId) {
        sessions.erase(sessionId);
    }
};

int main() {
    SessionManager manager;

    // Example usage
    std::string userId = "user123";
    std::string sessionId = manager.createSession(userId);
    std::cout << "Session created: " << sessionId << std::endl;

    bool isValid = manager.validateSession(sessionId);
    std::cout << "Session valid: " << std::boolalpha << isValid << std::endl;

    manager.endSession(sessionId);
    std::cout << "Session ended" << std::endl;

    isValid = manager.validateSession(sessionId);
    std::cout << "Session valid after ending: " << std::boolalpha << isValid << std::endl;

    return 0;
}

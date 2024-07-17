
#include <iostream>
#include <unordered_map>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>
#include <sstream>

class Session {
public:
    std::string sessionId;
    std::string userId;
    std::chrono::system_clock::time_point creationTime;
    std::chrono::system_clock::time_point lastActivity;

    Session(const std::string& userId) : userId(userId) {
        sessionId = generateUUID();
        creationTime = std::chrono::system_clock::now();
        lastActivity = creationTime;
    }

private:
    std::string generateUUID() {
        static int counter = 0;
        std::stringstream ss;
        auto now = std::chrono::system_clock::now();
        auto now_c = std::chrono::system_clock::to_time_t(now);
        ss << std::put_time(std::localtime(&now_c), "%Y%m%d%H%M%S") << "-" << ++counter;
        return ss.str();
    }
};

class SessionManager {
private:
    std::unordered_map<std::string, Session> sessions;
    std::chrono::seconds sessionTimeout;

public:
    SessionManager(int timeoutSeconds = 1800) : sessionTimeout(timeoutSeconds) {}

    std::string createSession(const std::string& userId) {
        Session session(userId);
        sessions[session.sessionId] = session;
        return session.sessionId;
    }

    Session* getSession(const std::string& sessionId) {
        auto it = sessions.find(sessionId);
        if (it != sessions.end()) {
            auto now = std::chrono::system_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(now - it->second.lastActivity) > sessionTimeout) {
                destroySession(sessionId);
                return nullptr;
            }
            it->second.lastActivity = now;
            return &(it->second);
        }
        return nullptr;
    }

    void destroySession(const std::string& sessionId) {
        sessions.erase(sessionId);
    }

    void cleanupExpiredSessions() {
        auto now = std::chrono::system_clock::now();
        for (auto it = sessions.begin(); it != sessions.end();) {
            if (std::chrono::duration_cast<std::chrono::seconds>(now - it->second.lastActivity) > sessionTimeout) {
                it = sessions.erase(it);
            } else {
                ++it;
            }
        }
    }
};

int main() {
    SessionManager sessionManager;

    // Create a session
    std::string userId = "user123";
    std::string sessionId = sessionManager.createSession(userId);
    std::cout << "Session created for user " << userId << ": " << sessionId << std::endl;

    // Get session
    Session* session = sessionManager.getSession(sessionId);
    if (session) {
        std::cout << "Session found for user " << session->userId << std::endl;
    } else {
        std::cout << "Session not found" << std::endl;
    }

    // Simulate session expiration
    std::this_thread::sleep_for(std::chrono::seconds(2));
    sessionManager = SessionManager(1); // Set timeout to 1 second for demonstration
    session = sessionManager.getSession(sessionId);
    if (session) {
        std::cout << "Session still active for user " << session->userId << std::endl;
    } else {
        std::cout << "Session expired" << std::endl;
    }

    // Cleanup expired sessions
    sessionManager.cleanupExpiredSessions();
    std::cout << "Expired sessions cleaned up" << std::endl;

    return 0;
}

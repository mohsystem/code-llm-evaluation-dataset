#include <iostream>
#include <unordered_map>
#include <string>
#include <random>

class Session {
public:
    std::string sessionId;
    std::string username;

    Session(const std::string& sessionId, const std::string& username) :
        sessionId(sessionId), username(username) {}
};

class SessionManager {
private:
    std::unordered_map<std::string, Session> sessions;
    std::random_device rd;
    std::mt19937 generator;

public:
    SessionManager() : generator(rd()) {}

    std::string createSession(const std::string& username) {
        std::uniform_int_distribution<char> distribution('a', 'z');
        std::string sessionId;
        for (int i = 0; i < 32; ++i) {
            sessionId += distribution(generator);
        }
        sessions[sessionId] = Session(sessionId, username);
        return sessionId;
    }

    Session* getSession(const std::string& sessionId) {
        auto it = sessions.find(sessionId);
        if (it != sessions.end()) {
            return &it->second;
        }
        return nullptr;
    }

    void invalidateSession(const std::string& sessionId) {
        sessions.erase(sessionId);
    }
};

int main() {
    SessionManager sessionManager;

    // Create a session for user "john.doe"
    std::string sessionId = sessionManager.createSession("john.doe");
    std::cout << "Created session: " << sessionId << std::endl;

    // Retrieve the session
    Session* session = sessionManager.getSession(sessionId);
    if (session != nullptr) {
        std::cout << "Retrieved session: " << session->sessionId << " - " << session->username << std::endl;
    }

    // Invalidate the session
    sessionManager.invalidateSession(sessionId);
    std::cout << "Invalidated session: " << sessionId << std::endl;

    return 0;
}
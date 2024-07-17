#include <iostream>
#include <string>
#include <vector>

class SessionManager {
private:
    std::vector<std::pair<std::string, std::string>> sessions;

public:
    void createUserSession(const std::string& userId, const std::string& sessionId) {
        sessions.push_back({userId, sessionId});
    }

    void deleteUserSession(const std::string& userId) {
        for (auto it = sessions.begin(); it != sessions.end(); ++it) {
            if (it->first == userId) {
                sessions.erase(it);
                break;
            }
        }
    }

    std::string getUserSessionId(const std::string& userId) {
        for (const auto& session : sessions) {
            if (session.first == userId) {
                return session.second;
            }
        }
        return "";
    }
};

int main() {
    SessionManager sessionManager;
    sessionManager.createUserSession("user1", "session1");
    sessionManager.createUserSession("user2", "session2");
    std::cout << sessionManager.getUserSessionId("user1") << std::endl; // prints "session1"
    sessionManager.deleteUserSession("user1");
    std::cout << sessionManager.getUserSessionId("user1") << std::endl; // prints empty string
    return 0;
}
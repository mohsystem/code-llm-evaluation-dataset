#include <iostream>
#include <string>
#include <map>
#include <uuid/uuid.h>

class SessionManager {
private:
    std::map<std::string, std::string> sessions;

public:
    SessionManager() {}

    std::string createSession(const std::string& userId) {
        std::string sessionId = generateSessionId();
        sessions[sessionId] = userId;
        return sessionId;
    }

    std::string generateSessionId() {
        uuid_t uuid;
        uuid_generate(uuid);
        char uuid_str[37];
        uuid_unparse(uuid, uuid_str);
        return std::string(uuid_str);
    }

    std::string getUserId(const std::string& sessionId) {
        return sessions[sessionId];
    }

    void invalidateSession(const std::string& sessionId) {
        sessions.erase(sessionId);
    }
};

int main() {
    SessionManager sessionManager;

    // create a session
    std::string sessionId = sessionManager.createSession("user1");
    std::cout << "Session ID: " << sessionId << std::endl;

    // get user id from session id
    std::string userId = sessionManager.getUserId(sessionId);
    std::cout << "User ID: " << userId << std::endl;

    // invalidate session
    sessionManager.invalidateSession(sessionId);
    std::cout << "Session invalidated" << std::endl;

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <uuid/uuid.h>

class UserSessionManager {
public:
    std::string createSession(const std::string &username) {
        std::string sessionId = generateUUID();
        sessions[sessionId] = username;
        return sessionId;
    }

    std::string getSession(const std::string &sessionId) {
        return sessions.count(sessionId) ? sessions[sessionId] : "";
    }

    void removeSession(const std::string &sessionId) {
        sessions.erase(sessionId);
    }

private:
    std::string generateUUID() {
        uuid_t uuid;
        char uuidStr[37];
        uuid_generate(uuid);
        uuid_unparse(uuid, uuidStr);
        return uuidStr;
    }

    std::unordered_map<std::string, std::string> sessions;
};

int main() {
    UserSessionManager sessionManager;
    std::string sessionId = sessionManager.createSession("JohnDoe");
    std::cout << "Session ID: " + sessionId << std::endl;
    std::cout << "User: " + sessionManager.getSession(sessionId) << std::endl;
    sessionManager.removeSession(sessionId);
    std::cout << "Session removed. User: " + sessionManager.getSession(sessionId) << std::endl;
    return 0;
}
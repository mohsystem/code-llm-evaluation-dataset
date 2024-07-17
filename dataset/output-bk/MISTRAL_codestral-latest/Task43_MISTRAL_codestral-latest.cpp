// C++
#include <map>
#include <string>
#include <uuid/uuid.h>

class SessionManager {
private:
    std::map<std::string, std::string> sessions;

public:
    std::string createSession(const std::string& userId) {
        uuid_t uuid;
        uuid_generate(uuid);
        char sessionId[37];
        uuid_unparse(uuid, sessionId);
        sessions[sessionId] = userId;
        return sessionId;
    }

    std::string getUserFromSession(const std::string& sessionId) {
        return sessions[sessionId];
    }

    void terminateSession(const std::string& sessionId) {
        sessions.erase(sessionId);
    }
};
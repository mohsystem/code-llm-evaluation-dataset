#include <iostream>
#include <string>
#include <vector>

class Session {
public:
    std::string id;
    // other session data
};

std::vector<Session> sessions;

void createSession(const std::string& id) {
    Session newSession;
    newSession.id = id;
    sessions.push_back(newSession);
}

void terminateSession(const std::string& id) {
    for (auto it = sessions.begin(); it != sessions.end(); ++it) {
        if (it->id == id) {
            sessions.erase(it);
            return;
        }
    }
}

int main() {
    // assume a web framework that provides the following functions
    std::string requestMethod = getRequestMethod();
    std::string requestId = getRequestParam("id");
    std::string requestAction = getRequestParam("action");

    if (requestMethod == "GET") {
        if (requestAction == "create") {
            createSession(requestId);
        } else if (requestAction == "terminate") {
            terminateSession(requestId);
        }
    }

    return 0;
}
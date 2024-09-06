#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>

using namespace std;

class Session {
public:
    string username;
    string session_id;
    time_t created_at;

    Session(string username) {
        this->username = username;
        this->created_at = time(0);
    }

    void createSession() {
        // In a real application, generate a unique session ID
        this->session_id = "session_" + username;
    }

    bool isValid() {
        // In a real application, check for session expiry
        return true;
    }
};

class SessionManager {
public:
    unordered_map<string, Session*> sessions;

    string createSession(string username) {
        Session* session = new Session(username);
        session->createSession();
        sessions[session->session_id] = session;
        return session->session_id;
    }

    Session* getSession(string session_id) {
        if (sessions.find(session_id) != sessions.end()) {
            return sessions[session_id];
        }
        return nullptr;
    }

    void deleteSession(string session_id) {
        if (sessions.find(session_id) != sessions.end()) {
            delete sessions[session_id];
            sessions.erase(session_id);
        }
    }
};

int main() {
    SessionManager session_manager;

    // Create a new session
    string session_id = session_manager.createSession("user1");
    cout << "Session created for user1 with ID: " << session_id << endl;

    // Get the session
    Session* session = session_manager.getSession(session_id);
    if (session != nullptr && session->isValid()) {
        cout << "Session is valid for user: " << session->username << endl;
    } else {
        cout << "Session is not valid" << endl;
    }

    // Delete the session
    session_manager.deleteSession(session_id);
    cout << "Session with ID " << session_id << " deleted" << endl;

    return 0;
}
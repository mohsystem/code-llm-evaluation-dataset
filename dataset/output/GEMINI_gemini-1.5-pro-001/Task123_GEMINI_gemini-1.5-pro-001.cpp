#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>

using namespace std;

class Session {
public:
    string username;
    time_t loginTime;

    Session(string username) {
        this->username = username;
        this->loginTime = time(nullptr);
    }

    string getSessionData() {
        string data = "Username: " + this->username + ", Login Time: " + ctime(&(this->loginTime));
        data.pop_back(); // remove trailing newline from ctime
        return data;
    }
};

unordered_map<string, Session*> sessions;

void createSession(string username) {
    sessions[username] = new Session(username);
    cout << "Session created for " << username << endl;
}

void getSession(string username) {
    if (sessions.find(username) != sessions.end()) {
        cout << sessions[username]->getSessionData() << endl;
    } else {
        cout << "Session not found for " << username << endl;
    }
}

void deleteSession(string username) {
    if (sessions.find(username) != sessions.end()) {
        delete sessions[username];
        sessions.erase(username);
        cout << "Session deleted for " << username << endl;
    } else {
        cout << "Session not found for " << username << endl;
    }
}

int main() {
    string action, username;
    while (true) {
        cout << "Enter action (create/get/delete/exit): ";
        cin >> action;
        if (action == "exit") {
            break;
        }
        cout << "Enter username: ";
        cin >> username;
        if (action == "create") {
            createSession(username);
        } else if (action == "get") {
            getSession(username);
        } else if (action == "delete") {
            deleteSession(username);
        } else {
            cout << "Invalid action" << endl;
        }
    }
    // Clean up allocated memory before exiting
    for (auto& session : sessions) {
        delete session.second;
    }
    return 0;
}
#include <iostream>

class UserSession {
private:
    int userId;
    bool active;

public:
    UserSession(int userId) {
        this->userId = userId;
        this->active = true;
    }

    void endSession() {
        this->active = false;
    }

    int getUserId() {
        return this->userId;
    }

    bool isActive() {
        return this->active;
    }
};

int main() {
    UserSession session(1);
    std::cout << session.getUserId() << std::endl;
    std::cout << (session.isActive() ? "true" : "false") << std::endl;
    session.endSession();
    std::cout << (session.isActive() ? "true" : "false") << std::endl;
    return 0;
}
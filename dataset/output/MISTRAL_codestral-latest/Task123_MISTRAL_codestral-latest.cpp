// C++
#include <iostream>

class Session {
    private:
        int userId;
        bool isActive;

    public:
        Session(int userId) {
            this->userId = userId;
            this->isActive = true;
        }

        void endSession() {
            this->isActive = false;
        }
};

// Example usage:
int main() {
    Session userSession(123);
    // ... user interacts with the system ...
    userSession.endSession();
    return 0;
}
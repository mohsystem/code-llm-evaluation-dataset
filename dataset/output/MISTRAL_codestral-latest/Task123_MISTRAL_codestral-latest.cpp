// C++
#include <iostream>

class Session {
private:
    int userId;
    bool isActive;

public:
    Session(int userId) : userId(userId), isActive(true) {}

    void endSession() {
        isActive = false;
    }
};

// Usage
int main() {
    Session userSession(123);
    std::cout << userSession.isActive << std::endl;  // 1 (true)
    userSession.endSession();
    std::cout << userSession.isActive << std::endl;  // 0 (false)
    return 0;
}
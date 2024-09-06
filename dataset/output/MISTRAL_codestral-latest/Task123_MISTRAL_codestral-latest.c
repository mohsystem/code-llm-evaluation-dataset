// C
#include <stdbool.h>

typedef struct {
    int userId;
    bool isActive;
} Session;

Session createSession(int userId) {
    Session session;
    session.userId = userId;
    session.isActive = true;
    return session;
}

void endSession(Session* session) {
    session->isActive = false;
}

// Example usage:
int main() {
    Session userSession = createSession(123);
    // ... user interacts with the system ...
    endSession(&userSession);
    return 0;
}
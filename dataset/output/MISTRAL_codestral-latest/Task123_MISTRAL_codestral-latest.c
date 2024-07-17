// C
#include <stdio.h>
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

// Usage
int main() {
    Session userSession = createSession(123);
    printf("%d
", userSession.isActive);  // 1 (true)
    endSession(&userSession);
    printf("%d
", userSession.isActive);  // 0 (false)
    return 0;
}
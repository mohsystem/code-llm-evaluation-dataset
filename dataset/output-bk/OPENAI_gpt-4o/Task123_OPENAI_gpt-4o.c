#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int userId;
    bool active;
} UserSession;

UserSession createUserSession(int userId) {
    UserSession session;
    session.userId = userId;
    session.active = true;
    return session;
}

void endSession(UserSession *session) {
    session->active = false;
}

int getUserId(UserSession *session) {
    return session->userId;
}

bool isActive(UserSession *session) {
    return session->active;
}

int main() {
    UserSession session = createUserSession(1);
    printf("%d
", getUserId(&session));
    printf("%s
", isActive(&session) ? "true" : "false");
    endSession(&session);
    printf("%s
", isActive(&session) ? "true" : "false");
    return 0;
}
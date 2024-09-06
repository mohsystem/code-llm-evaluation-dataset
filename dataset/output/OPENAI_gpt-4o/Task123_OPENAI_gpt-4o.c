#include <stdio.h>
#include <time.h>
#include <unistd.h>

typedef struct UserSession {
    char userId[50];
    time_t startTime;
} UserSession;

UserSession create_session(const char *userId) {
    UserSession session;
    snprintf(session.userId, sizeof(session.userId), "%s", userId);
    session.startTime = time(NULL);
    return session;
}

double get_duration(UserSession *session) {
    return difftime(time(NULL), session->startTime);
}

int main() {
    UserSession session = create_session("User1");
    sleep(2);
    printf("C: Session duration for %s: %.2f seconds\n", session.userId, get_duration(&session));
    return 0;
}
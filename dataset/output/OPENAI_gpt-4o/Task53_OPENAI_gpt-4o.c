#include <stdio.h>
#include <string.h>

typedef struct {
    char sessionId[20];
    char userId[20];
} UserSession;

void toString(UserSession session, char *output) {
    sprintf(output, "Session ID: %s, User ID: %s", session.sessionId, session.userId);
}

int main() {
    UserSession session;
    strcpy(session.sessionId, "abc123");
    strcpy(session.userId, "user001");

    char output[100];
    toString(session, output);
    printf("%s\n", output);
    return 0;
}
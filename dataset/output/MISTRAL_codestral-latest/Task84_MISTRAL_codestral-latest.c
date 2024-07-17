#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateSessionId(char *sessionId) {
    for (int i = 0; i < 36; i++) {
        int r = rand() % 16;
        sessionId[i] = (r < 10) ? ('0' + r) : ('a' + r - 10);
        if (i == 8 || i == 13 || i == 18 || i == 23)
            sessionId[i] = '-';
    }
    sessionId[36] = '\0';
}

int main() {
    srand(time(0));
    char sessionId[37];
    generateSessionId(sessionId);
    printf("%s
", sessionId);
    return 0;
}
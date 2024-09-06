
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SESSION_ID_LENGTH 32

void generate_session_id(char *session_id) {
    const char charset[] = "0123456789abcdef";
    int i;

    srand(time(NULL));

    for (i = 0; i < SESSION_ID_LENGTH; i++) {
        if (i == 8 || i == 13 || i == 18 || i == 23) {
            session_id[i] = '-';
        } else {
            int index = rand() % (sizeof(charset) - 1);
            session_id[i] = charset[index];
        }
    }
    session_id[SESSION_ID_LENGTH] = '\\0';
}

int main() {
    char session_id[SESSION_ID_LENGTH + 1];
    generate_session_id(session_id);
    printf("%s\\n", session_id);
    return 0;
}

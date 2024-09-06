#include <stdio.h>
#include <uuid/uuid.h>

char* generateSessionId() {
    uuid_t uuid;
    uuid_generate_random(uuid);
    char *str = (char*)malloc(37);
    uuid_unparse(uuid, str);
    return str;
}

int main() {
    char *sessionId = generateSessionId();
    printf("%s\n", sessionId);
    free(sessionId);
    return 0;
}
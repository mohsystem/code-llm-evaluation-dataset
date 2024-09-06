// C
// C does not support classes or maps directly, so this example is more complex.
// We'll use a linked list to store sessions and a simple hash function to map user IDs to sessions.

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Session {
    char* userId;
    bool isActive;
    struct Session* next;
} Session;

// Hash function for user IDs
unsigned int hash(const char* str) {
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 100; // Modulo to keep the hash within a reasonable range
}

// Example usage:
int main() {
    Session* userSessions[100] = {NULL}; // Array of 100 pointers to Session
    const char* userId = "123";
    unsigned int index = hash(userId);

    Session* newSession = malloc(sizeof(Session));
    newSession->userId = strdup(userId);
    newSession->isActive = true;
    newSession->next = userSessions[index];
    userSessions[index] = newSession;

    return 0;
}
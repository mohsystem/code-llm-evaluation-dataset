#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int sessionId = rand();
    printf("Session ID: %d
", sessionId);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char* generate_session_id() {
    static char session_id[37];
    srand(time(NULL));
    for(int i = 0; i < 32; i++) {
        session_id[i] = "0123456789abcdef"[rand() % 16];
    }
    session_id[32] = '\0';
    return session_id;
}
int main() {
    printf("%s\n", generate_session_id());
    return 0;
}
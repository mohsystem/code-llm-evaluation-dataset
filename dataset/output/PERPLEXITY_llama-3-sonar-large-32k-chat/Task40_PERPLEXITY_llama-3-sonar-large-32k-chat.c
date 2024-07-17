#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

int main() {
    uuid_t uuid;
    char csrfToken[37];
    uuid_generate_random(uuid);
    uuid_unparse(uuid, csrfToken);
    printf("CSRF Token: %s
", csrfToken);
    return 0;
}
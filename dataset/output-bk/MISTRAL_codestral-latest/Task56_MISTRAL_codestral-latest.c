// C
#include <stdio.h>
#include <uuid/uuid.h>

int main() {
    uuid_t token;
    uuid_generate(token);
    char str[37];
    uuid_unparse(token, str);
    printf("Generated Token: %s
", str);
    return 0;
}
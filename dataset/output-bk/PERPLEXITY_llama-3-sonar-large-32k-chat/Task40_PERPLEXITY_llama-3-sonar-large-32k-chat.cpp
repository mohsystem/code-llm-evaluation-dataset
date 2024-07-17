#include <iostream>
#include <string>
#include <uuid/uuid.h>

int main() {
    uuid_t uuid;
    char csrfToken[37];
    uuid_generate_random(uuid);
    uuid_unparse(uuid, csrfToken);
    std::cout << "CSRF Token: " << csrfToken << std::endl;
    return 0;
}
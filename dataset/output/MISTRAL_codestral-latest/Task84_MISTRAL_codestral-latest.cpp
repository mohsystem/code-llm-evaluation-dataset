#include <iostream>
#include <uuid/uuid.h>

std::string generateSessionId() {
    uuid_t uuid;
    uuid_generate_random(uuid);
    char str[37];
    uuid_unparse(uuid, str);
    return std::string(str);
}

int main() {
    std::cout << generateSessionId() << std::endl;
    return 0;
}
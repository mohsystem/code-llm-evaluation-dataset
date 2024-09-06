#include <iostream>
#include <uuid/uuid.h>
int main() {
    uuid_t uuid;
    uuid_generate_random(uuid);
    char uuid_str[37];
    uuid_unparse(uuid, uuid_str);
    std::cout << uuid_str << std::endl;
    return 0;
}
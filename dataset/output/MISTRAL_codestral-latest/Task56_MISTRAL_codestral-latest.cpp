// C++
#include <iostream>
#include <uuid/uuid.h>

int main() {
    uuid_t token;
    uuid_generate(token);
    char str[37];
    uuid_unparse(token, str);
    std::cout << "Generated Token: " << str << std::endl;
    return 0;
}
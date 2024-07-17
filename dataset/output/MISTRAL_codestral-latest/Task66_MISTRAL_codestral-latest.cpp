#include <iostream>
#include <cstdlib>
#include <cstring>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    std::cout << "Enter a shell command:
";
    std::cin.getline(command, MAX_COMMAND_LENGTH);

    int result = std::system(command);

    if (result == -1) {
        std::cerr << "Error executing command
";
        return 1;
    }

    return 0;
}
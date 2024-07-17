#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    char *end;
    long num = strtol(argv[1], &end, 10);

    if (*end != '\0' || num < INT_MIN || num > INT_MAX) {
        std::cout << "Invalid input. Please enter an integer.
";
    } else {
        std::cout << "The integer is: " << num << "
";
    }

    return 0;
}
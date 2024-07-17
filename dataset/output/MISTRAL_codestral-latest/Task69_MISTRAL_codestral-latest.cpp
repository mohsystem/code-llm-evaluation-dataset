// C++
#include <iostream>
#include <cstdio>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        if (std::remove(argv[1]) == 0) {
            std::cout << "File deleted successfully
";
        } else {
            std::cout << "Unable to delete the file
";
        }
    } else {
        std::cout << "Please provide a file path as an argument
";
    }
    return 0;
}
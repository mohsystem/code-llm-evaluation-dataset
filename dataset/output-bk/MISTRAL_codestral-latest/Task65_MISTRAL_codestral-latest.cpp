// C++
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Please provide a filename as a command line argument.
";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::perror("Error opening file");
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << '
';
    }

    file.close();
    return 0;
}
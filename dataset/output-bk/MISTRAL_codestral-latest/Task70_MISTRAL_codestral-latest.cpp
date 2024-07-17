#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        std::ifstream file(argv[1]);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << '
';
            }
            file.close();
        } else {
            std::cout << "Unable to open the file.
";
        }
    } else {
        std::cout << "Please provide a file path as an argument.
";
    }
    return 0;
}
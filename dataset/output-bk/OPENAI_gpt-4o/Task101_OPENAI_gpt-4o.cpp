#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    std::ofstream file("script.sh");
    if (file.is_open()) {
        file << "#!/bin/bash
";
        file << "echo Hello, World!";
        file.close();
        system("chmod +x script.sh");
        std::cout << "script.sh created and made executable." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
    return 0;
}
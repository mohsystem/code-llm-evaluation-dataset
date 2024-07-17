#include <iostream>
#include <string>
#include <fstream>

int main() {
    std::string cmd;
    std::cout << "Enter a bash command: ";
    std::getline(std::cin, cmd);

    std::FILE *fp = popen(cmd.c_str(), "r");
    if (fp == NULL) {
        std::cerr << "Error executing command" << std::endl;
        return 1;
    }

    char output[1024];
    while (std::fgets(output, 1024, fp) != NULL) {
        std::cout << output;
    }

    pclose(fp);
    return 0;
}
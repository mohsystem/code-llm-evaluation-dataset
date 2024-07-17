
#include <iostream>
#include <string>
#include <cstdlib>
#include <array>
#include <memory>

int main() {
    std::string filename;
    std::cout << "Enter the filename: ";
    std::getline(std::cin, filename);

    std::string command = "cat " + filename;

    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        std::cerr << "popen() failed!" << std::endl;
        return 1;
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    std::cout << result;

    return 0;
}

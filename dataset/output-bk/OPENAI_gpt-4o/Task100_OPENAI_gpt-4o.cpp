#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: <pattern> <filename>" << std::endl;
        return 1;
    }
    std::string pattern = argv[1];
    std::string filename = argv[2];

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::perror("ifstream");
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    std::regex reg(pattern);
    std::sregex_iterator next(content.begin(), content.end(), reg);
    std::sregex_iterator end;

    while (next != end) {
        std::cout << next->str() << '
';
        ++next;
    }

    return 0;
}
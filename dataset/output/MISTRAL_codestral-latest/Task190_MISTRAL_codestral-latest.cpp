#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() {
    std::ifstream file("file.txt");
    std::vector<std::vector<std::string>> lines;
    std::string line, word;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> words;
        while (ss >> word) {
            words.push_back(word);
        }
        lines.push_back(words);
    }

    for (int i = 0; i < lines[0].size(); i++) {
        for (int j = 0; j < lines.size(); j++) {
            std::cout << lines[j][i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
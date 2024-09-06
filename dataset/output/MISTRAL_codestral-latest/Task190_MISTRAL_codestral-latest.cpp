// C++
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
    file.close();

    std::vector<std::vector<std::string>> transposed(lines[0].size(), std::vector<std::string>(lines.size()));
    for (size_t i = 0; i < lines.size(); i++) {
        for (size_t j = 0; j < lines[i].size(); j++) {
            transposed[j][i] = lines[i][j];
        }
    }

    for (const auto &row : transposed) {
        for (const auto &word : row) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
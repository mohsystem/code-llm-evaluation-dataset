#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::ifstream file("file.txt");
    std::vector<std::vector<std::string>> lines;
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> temp;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            temp.push_back(word);
        }
        lines.push_back(temp);
    }
    file.close();
    for (int i = 0; i < lines[0].size(); i++) {
        for (int j = 0; j < lines.size(); j++) {
            std::cout << lines[j][i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
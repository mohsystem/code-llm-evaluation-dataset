// C++
#include <iostream>
#include <fstream>
#include <cctype>

void caesarCipher(int shift, std::string inputFile, std::string outputFile) {
    std::ifstream input(inputFile);
    std::ofstream output(outputFile);
    char character;
    while (input.get(character)) {
        if (isalpha(character)) {
            if (islower(character)) {
                character = (character - 'a' + shift) % 26 + 'a';
            } else {
                character = (character - 'A' + shift) % 26 + 'A';
            }
        }
        output << character;
    }
    input.close();
    output.close();
}

int main() {
    int shift;
    std::string inputFile, outputFile;
    std::cout << "Enter the shift value: ";
    std::cin >> shift;
    std::cout << "Enter the input file path: ";
    std::cin >> inputFile;
    std::cout << "Enter the output file path: ";
    std::cin >> outputFile;
    caesarCipher(shift, inputFile, outputFile);
    return 0;
}
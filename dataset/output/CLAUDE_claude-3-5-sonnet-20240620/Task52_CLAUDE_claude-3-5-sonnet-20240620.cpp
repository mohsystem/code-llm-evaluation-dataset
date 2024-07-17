
#include <iostream>
#include <fstream>
#include <string>

const char KEY = 0x42;

void encrypt_decrypt(const std::string& input_file, const std::string& output_file) {
    std::ifstream fin(input_file, std::ios::binary);
    std::ofstream fout(output_file, std::ios::binary);

    if (!fin) {
        std::cerr << "Error opening input file." << std::endl;
        return;
    }

    if (!fout) {
        std::cerr << "Error opening output file." << std::endl;
        return;
    }

    char ch;
    while (fin.get(ch)) {
        fout.put(ch ^ KEY);
    }

    fin.close();
    fout.close();
}

int main() {
    char choice;
    std::string input_file, output_file;

    std::cout << "Enter \'e\' to encrypt or \'d\' to decrypt: ";
    std::cin >> choice;
    std::cout << "Enter input file name: ";
    std::cin >> input_file;
    std::cout << "Enter output file name: ";
    std::cin >> output_file;

    encrypt_decrypt(input_file, output_file);
    std::cout << "Operation completed successfully." << std::endl;

    return 0;
}

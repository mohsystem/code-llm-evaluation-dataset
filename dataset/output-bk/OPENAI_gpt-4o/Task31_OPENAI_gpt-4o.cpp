#include <iostream>
#include <unordered_map>

std::string dna_complement(const std::string& dna) {
    std::unordered_map<char, char> dna_map = {
        {'A', 'T'},
        {'T', 'A'},
        {'C', 'G'},
        {'G', 'C'}
    };
    
    std::string result;
    for (char c : dna) {
        result += dna_map[c];
    }
    return result;
}

int main() {
    std::string inputs[] = {"ATTGC", "GTAT"};
    for (const std::string& input : inputs) {
        std::cout << dna_complement(input) << std::endl;
    }
    return 0;
}
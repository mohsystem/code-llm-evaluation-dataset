#include <iostream>
#include <string>

std::string dnaStrand(const std::string& dna) {
    std::string complement = "";
    for (char base : dna) {
        switch (base) {
            case 'A':
                complement += 'T';
                break;
            case 'T':
                complement += 'A';
                break;
            case 'C':
                complement += 'G';
                break;
            case 'G':
                complement += 'C';
                break;
        }
    }
    return complement;
}

int main() {
    std::cout << dnaStrand("ATTGC") << std::endl;  // Output: TAACG
    std::cout << dnaStrand("GTAT") << std::endl;   // Output: CATA
    return 0;
}
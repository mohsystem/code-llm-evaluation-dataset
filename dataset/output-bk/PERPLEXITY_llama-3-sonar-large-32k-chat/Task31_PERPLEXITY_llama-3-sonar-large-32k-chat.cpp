#include <iostream>
#include <string>

std::string DNATranslate(std::string dna) {
    std::string complement;
    for (char c : dna) {
        switch (c) {
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
    std::string dna1 = "ATTGC";
    std::string dna2 = "GTAT";
    std::cout << dna1 << " --> " << DNATranslate(dna1) << std::endl; // --> "TAACG"
    std::cout << dna2 << " --> " << DNATranslate(dna2) << std::endl; // --> "CATA"
    return 0;
}
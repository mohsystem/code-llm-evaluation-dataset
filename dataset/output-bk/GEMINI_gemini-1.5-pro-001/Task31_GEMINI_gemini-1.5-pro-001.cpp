#include <iostream>
#include <string>

std::string makeComplement(const std::string& dna) {
    std::string complement = "";
    for (char nucleotide : dna) {
        switch (nucleotide) {
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
            default: 
                complement += '?'; 
        }
    }
    return complement;
}

int main() {
    std::string dnaStrand;
    std::cout << "Enter DNA strand: ";
    std::cin >> dnaStrand;

    std::cout << makeComplement(dnaStrand) << std::endl;
    return 0;
}
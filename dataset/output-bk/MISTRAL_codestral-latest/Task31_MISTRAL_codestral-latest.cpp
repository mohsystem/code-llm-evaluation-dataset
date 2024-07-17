#include <iostream>
#include <string>

std::string makeComplement(std::string dna) {
    for (int i = 0; i < dna.length(); i++) {
        switch (dna[i]) {
            case 'A':
                dna[i] = 'T';
                break;
            case 'T':
                dna[i] = 'A';
                break;
            case 'C':
                dna[i] = 'G';
                break;
            case 'G':
                dna[i] = 'C';
                break;
        }
    }
    return dna;
}
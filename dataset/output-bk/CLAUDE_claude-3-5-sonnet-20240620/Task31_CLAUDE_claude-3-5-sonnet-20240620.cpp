
#include <iostream>
#include <string>

std::string make_complement(std::string dna) {
    for (char& c : dna) {
        switch (c) {
            case \'A\':
                c = \'T\';
                break;
            case \'T\':
                c = \'A\';
                break;
            case \'C\':
                c = \'G\';
                break;
            case \'G\':
                c = \'C\';
                break;
        }
    }
    return dna;
}

int main() {
    std::cout << make_complement("ATTGC") << std::endl; // Output: TAACG
    std::cout << make_complement("GTAT") << std::endl;  // Output: CATA
    return 0;
}

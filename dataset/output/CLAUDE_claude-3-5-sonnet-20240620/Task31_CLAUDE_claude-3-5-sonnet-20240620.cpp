
#include <string>

std::string DNAStrand(const std::string& dna)
{
    std::string result = dna;
    for(char& c : result) {
        switch(c) {
            case 'A': c = 'T'; break;
            case 'T': c = 'A'; break;
            case 'C': c = 'G'; break;
            case 'G': c = 'C'; break;
        }
    }
    return result;
}

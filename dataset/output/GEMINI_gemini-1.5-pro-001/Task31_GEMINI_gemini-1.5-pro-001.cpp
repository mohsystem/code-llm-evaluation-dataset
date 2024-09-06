#include <string>

std::string DNA_strand(const std::string& dna) {
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
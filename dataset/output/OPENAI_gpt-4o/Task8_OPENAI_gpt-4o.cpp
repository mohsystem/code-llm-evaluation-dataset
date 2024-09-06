#include <iostream>

char findMissingLetter(char array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] - array[i] != 1) {
            return array[i] + 1;
        }
    }
    throw std::invalid_argument("No missing letter found");
}

int main() {
    std::cout << findMissingLetter(new char[]{ 'a', 'b', 'c', 'd', 'f' }, 5) << std::endl; // e
    std::cout << findMissingLetter(new char[]{ 'O', 'Q', 'R', 'S' }, 4) << std::endl; // P
    return 0;
}
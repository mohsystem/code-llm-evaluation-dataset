#include <iostream>
#include <vector>

char findMissingLetter(std::vector<char> array) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        if (array[i + 1] != array[i] + 1) {
            return array[i] + 1;
        }
    }
    throw std::invalid_argument("No missing letter detected.");
}

int main() {
    std::vector<char> array1 = {'a', 'b', 'c', 'd', 'f'};
    std::vector<char> array2 = {'O', 'Q', 'R', 'S'};
    
    std::cout << findMissingLetter(array1) << std::endl; // Output: e
    std::cout << findMissingLetter(array2) << std::endl; // Output: P
    
    return 0;
}
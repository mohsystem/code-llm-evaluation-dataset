
#include <iostream>
#include <vector>

char findMissingLetter(std::vector<char> array) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        if (array[i + 1] - array[i] > 1) {
            return array[i] + 1;
        }
    }
    return \' \';
}

int main() {
    std::cout << findMissingLetter({\'a\',\'b\',\'c\',\'d\',\'f\'}) << std::endl;
    std::cout << findMissingLetter({\'O\',\'Q\',\'R\',\'S\'}) << std::endl;
    return 0;
}

#include <vector>
#include <cctype>

char findMissingLetter(std::vector<char> array) {
    for (int i = 1; i < array.size(); i++) {
        if (array[i] - array[i - 1] > 1) {
            return static_cast<char>(array[i] - 1);
        }
    }
    return '\0';
}
#include <iostream>

char findMissingLetter(char array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i + 1] - array[i] > 1) {
            return (char) (array[i] + 1);
        }
    }
    return ' ';
}

int main() {
    char arr[] = {'a','b','c','d','f'};
    int size = sizeof(arr) / sizeof(arr[0]);
    std::cout << findMissingLetter(arr, size) << std::endl;
    return 0;
}
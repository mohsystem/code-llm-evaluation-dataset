#include <iostream>

int findOddOccurrence(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    return result;
}

int main() {
    std::cout << findOddOccurrence((int[]){7}, 1) << std::endl;
    std::cout << findOddOccurrence((int[]){0}, 1) << std::endl;
    std::cout << findOddOccurrence((int[]){1, 1, 2}, 3) << std::endl;
    std::cout << findOddOccurrence((int[]){0, 1, 0, 1, 0}, 5) << std::endl;
    std::cout << findOddOccurrence((int[]){1, 2, 2, 3, 3, 3, 4, 3, 3, 3, 2, 2, 1}, 13) << std::endl;
    return 0;
}
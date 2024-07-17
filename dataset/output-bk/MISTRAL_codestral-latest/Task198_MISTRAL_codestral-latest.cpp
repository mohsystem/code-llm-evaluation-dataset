#include <cstdlib>

int rand7() {
    // This is a placeholder function.
    // In a real-world scenario, this function would return a uniform random integer in the range [1, 7].
    return 0;
}

int rand10() {
    while (true) {
        // Generate a number in the range [1, 49]
        int num = (rand7() - 1) * 7 + rand7();
        // If the number is in the range [1, 40], return a number in the range [1, 10]
        if (num <= 40) {
            return num % 10 + 1;
        }
    }
}
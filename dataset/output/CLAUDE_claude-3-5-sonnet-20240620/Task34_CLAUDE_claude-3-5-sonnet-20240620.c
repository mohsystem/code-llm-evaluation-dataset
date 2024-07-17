
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isNarcissistic(int number) {
    int originalNumber = number;
    int numDigits = 0;
    int sum = 0;

    // Count the number of digits
    while (number > 0) {
        numDigits++;
        number /= 10;
    }

    number = originalNumber;

    // Calculate the sum of digits raised to the power of numDigits
    while (number > 0) {
        int digit = number % 10;
        sum += pow(digit, numDigits);
        number /= 10;
    }

    return sum == originalNumber;
}

int main() {
    printf("%s\
", isNarcissistic(153) ? "true" : "false");  // true
    printf("%s\
", isNarcissistic(1652) ? "true" : "false"); // false
    return 0;
}

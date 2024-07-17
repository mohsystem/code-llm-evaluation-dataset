// C Code
#include <stdio.h>
#include <math.h>

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

int isNarcissistic(int number) {
    int originalNumber = number;
    int sum = 0;
    int numberOfDigits = countDigits(number);
    while (number > 0) {
        int digit = number % 10;
        sum += pow(digit, numberOfDigits);
        number /= 10;
    }
    return sum == originalNumber;
}

int main() {
    int num = 153; // example number
    printf("%d
", isNarcissistic(num));
    return 0;
}
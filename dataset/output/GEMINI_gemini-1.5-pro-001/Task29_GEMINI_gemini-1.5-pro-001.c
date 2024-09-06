#include <stdio.h>
#include <stdlib.h>

// Structure to represent a tuple of two integers
typedef struct {
    int index1;
    int index2;
} Tuple;

// Function to find two numbers in an array that add up to a target
Tuple two_sum(int numbers[], int size, int target) {
    Tuple result = {-1, -1}; 
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] + numbers[j] == target) {
                result.index1 = i;
                result.index2 = j;
                return result;
            }
        }
    }
    return result;
}
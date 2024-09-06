// Note: C doesn't have built-in heap data structures or OOP features like classes. 
//       You would typically use a library or implement heaps manually.

// This C code provides a basic example without using heaps, which might not be efficient
// for large datasets. 

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50000 

int arr[MAX_SIZE]; 
int count = 0; 

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void addNum(int num) {
    if (count < MAX_SIZE) {
        arr[count++] = num;
        qsort(arr, count, sizeof(int), compare); // Sort after adding each element
    } else {
        // Handle overflow if needed
    }
}

double findMedian() {
    if (count == 0) {
        return 0.0; // Or handle the empty case differently
    } else if (count % 2 == 0) {
        return (double)(arr[count / 2 - 1] + arr[count / 2]) / 2;
    } else {
        return (double)arr[count / 2];
    }
}
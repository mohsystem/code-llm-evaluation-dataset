// C is not well-suited for web development and session management
// without using external libraries or frameworks.
// This example demonstrates a basic concept of session management
// using a global variable, but it's not a production-ready solution.
#include <stdio.h>

// Simulate a session variable (not thread-safe)
int visits = 0;

int main() {
    visits++;
    printf("You have visited this page %d times.\n", visits);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Seed for random number generator
    srand((unsigned int)time(NULL));

    // Random string generation
    char randomString[8];
    for (int i = 0; i < 7; ++i) {
        randomString[i] = (char)(rand() % 94 + 32); // ensuring printable characters
    }
    randomString[7] = '\0';

    // Convert string to Unicode
    // In C, we usually deal with bytes; assuming randomString is already utf-8 compatible

    // Create temporary file
    char tempFileName[] = "tempXXXXXX.txt";
    int fd = mkstemps(tempFileName, 4);
    FILE *tempFile = fdopen(fd, "w");

    // Write to the file
    fprintf(tempFile, "%s", randomString);
    fclose(tempFile);

    // Return the path
    printf("File path: %s
", tempFileName);
    return 0;
}
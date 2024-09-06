#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char* createTempFileWithUnicode() {
    char *tempFilePath = NULL;
    char tempFileName[] = "/tmp/tempXXXXXX";
    int fd;

    // Generate a random string
    char randomString[] = "TestUnicodeString"; // Placeholder, replace with actual random generation if needed

    // Create temporary file with read/write permissions
    fd = mkstemp(tempFileName); 
    if (fd == -1) {
        perror("Error creating temporary file");
        return NULL; 
    }

    // Convert to dynamically allocated string for return
    tempFilePath = strdup(tempFileName);
    if (tempFilePath == NULL) {
        perror("Error duplicating string");
        close(fd); 
        unlink(tempFileName);
        return NULL;
    }

    // Write the string to the file 
    size_t bytesWritten = write(fd, randomString, strlen(randomString));
    if (bytesWritten != strlen(randomString)) {
        perror("Error writing to temporary file");
        close(fd);
        unlink(tempFilePath); 
        free(tempFilePath); 
        return NULL;
    }

    close(fd);
    return tempFilePath; 
}

int main() {
    char* tempFilePath = createTempFileWithUnicode();
    if (tempFilePath != NULL) {
        printf("Temporary file created at: %s\n", tempFilePath);
        free(tempFilePath); // Free the allocated memory
    }

    return 0;
}
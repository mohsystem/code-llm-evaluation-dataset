#include <stdio.h>
#include <stdlib.h>

char* readFile(const char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        return "File not found.";
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        fclose(file);
        return "Memory allocation failed.";
    }

    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        fclose(file);
        free(buffer);
        return "Error reading the file.";
    }

    buffer[fileSize] = '\0';
    fclose(file);
    return buffer;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./program <file_path>\n");
        return 1;
    }

    const char* filePath = argv[1];
    char* content = readFile(filePath);
    printf("%s\n", content);

    free(content);
    return 0;
}
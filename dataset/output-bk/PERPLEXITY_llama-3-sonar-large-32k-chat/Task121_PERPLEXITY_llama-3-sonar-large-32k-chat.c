#include <stdio.h>
#include <string.h>

void uploadFile(const char* filePath) {
    FILE* file = fopen(filePath, "rb");
    FILE* outputFile = fopen("uploaded_", "wb");
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = (char*)malloc(fileSize * sizeof(char));
    fread(buffer, fileSize, 1, file);
    fwrite(buffer, fileSize, 1, outputFile);
    fclose(file);
    fclose(outputFile);
    free(buffer);
}

int main() {
    char filePath[256];
    printf("Enter the file path: ");
    fgets(filePath, 256, stdin);
    filePath[strcspn(filePath, "
")] = 0; // remove newline character
    uploadFile(filePath);
    printf("File uploaded successfully!
");
    return 0;
}
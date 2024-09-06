
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

char* create_temp_file_with_unicode() {
    // Create a temporary file
    char temp_filename[] = "tempfileXXXXXX";
    #ifdef _WIN32
    _mktemp(temp_filename);
    #else
    mkstemp(temp_filename);
    #endif
    
    FILE* temp_file = fopen(temp_filename, "w");
    if (temp_file == NULL) {
        perror("Error creating temporary file");
        return NULL;
    }

    // Generate a random string
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char random_string[11];
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        random_string[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    random_string[10] = '\\0';

    // Convert the string to Unicode and write to file
    for (int i = 0; i < 10; i++) {
        fprintf(temp_file, "\\\\u%04X", (unsigned int)random_string[i]);
    }

    fclose(temp_file);

    char* result = malloc(strlen(temp_filename) + 1);
    if (result == NULL) {
        perror("Error allocating memory");
        return NULL;
    }
    strcpy(result, temp_filename);
    return result;
}

int main() {
    char* temp_file_path = create_temp_file_with_unicode();
    if (temp_file_path != NULL) {
        printf("%s\\n", temp_file_path);
        free(temp_file_path);
    }
    return 0;
}

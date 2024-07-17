
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

#define MAX_LENGTH 11

char* generate_random_string(int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    char* result = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        result[i] = charset[index];
    }
    result[length] = \'\\0\';
    return result;
}

wchar_t* convert_to_unicode(const char* input) {
    size_t len = strlen(input);
    wchar_t* result = malloc((len + 1) * sizeof(wchar_t));
    mbstowcs(result, input, len + 1);
    return result;
}

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));

    char template[] = "unicode_XXXXXX";
    int fd = mkstemp(template);
    if (fd == -1) {
        perror("Failed to create temporary file");
        return 1;
    }

    FILE* temp_file = fdopen(fd, "w");
    if (temp_file == NULL) {
        perror("Failed to open temporary file");
        close(fd);
        return 1;
    }

    char* random_string = generate_random_string(10);
    wchar_t* unicode_string = convert_to_unicode(random_string);

    fwprintf(temp_file, L"%ls", unicode_string);
    fclose(temp_file);

    printf("Temporary file path: %s\
", template);

    free(random_string);
    free(unicode_string);
    return 0;
}

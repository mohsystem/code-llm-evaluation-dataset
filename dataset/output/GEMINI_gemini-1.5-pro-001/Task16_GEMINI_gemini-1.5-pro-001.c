#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool solution(const char *string, const char *ending) {
    size_t string_len = strlen(string);
    size_t ending_len = strlen(ending);

    if (string_len < ending_len) {
        return false;
    }

    return (strcmp(string + string_len - ending_len, ending) == 0);
}
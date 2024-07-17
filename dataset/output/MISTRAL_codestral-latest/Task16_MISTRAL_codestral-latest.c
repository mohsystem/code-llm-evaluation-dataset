#include <string.h>
#include <stdbool.h>

bool solution(const char *str, const char *ending) {
    size_t str_len = strlen(str);
    size_t ending_len = strlen(ending);
    if (ending_len > str_len) return false;
    return strncmp(str + str_len - ending_len, ending, ending_len) == 0;
}
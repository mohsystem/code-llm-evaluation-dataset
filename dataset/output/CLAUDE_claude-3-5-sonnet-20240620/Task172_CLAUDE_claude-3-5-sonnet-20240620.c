
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 2000

typedef struct {
    char* key;
    UT_hash_handle hh;
} HashEntry;

HashEntry* result = NULL;

void add_to_set(const char* str) {
    HashEntry* entry;
    HASH_FIND_STR(result, str, entry);
    if (entry == NULL) {
        entry = (HashEntry*)malloc(sizeof(HashEntry));
        entry->key = strdup(str);
        HASH_ADD_KEYPTR(hh, result, entry->key, strlen(entry->key), entry);
    }
}

int distinctEchoSubstrings(char* text) {
    int n = strlen(text);
    result = NULL;
    
    for (int i = 0; i < n; i++) {
        for (int length = 1; length <= (n - i) / 2; length++) {
            if (strncmp(text + i, text + i + length, length) == 0) {
                char* substr = (char*)malloc((2 * length + 1) * sizeof(char));
                strncpy(substr, text + i, 2 * length);
                substr[2 * length] = '\\0';
                add_to_set(substr);
                free(substr);
            }
        }
    }
    
    int count = HASH_COUNT(result);
    
    HashEntry* current, *tmp;
    HASH_ITER(hh, result, current, tmp) {
        HASH_DEL(result, current);
        free(current->key);
        free(current);
    }
    
    return count;
}

int main() {
    printf("%d\\n", distinctEchoSubstrings("abcabcabc"));  // Output: 3
    printf("%d\\n", distinctEchoSubstrings("leetcodeleetcode"));  // Output: 2
    return 0;
}

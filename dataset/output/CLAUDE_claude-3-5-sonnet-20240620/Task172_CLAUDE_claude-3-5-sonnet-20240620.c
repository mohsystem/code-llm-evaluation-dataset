
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 2000

typedef struct {
    char* key;
    UT_hash_handle hh;
} HashEntry;

bool isEchoSubstring(const char* text, int start, int length) {
    for (int i = 0; i < length; i++) {
        if (text[start + i] != text[start + length + i]) {
            return false;
        }
    }
    return true;
}

int distinctEchoSubstrings(char* text) {
    int n = strlen(text);
    HashEntry* set = NULL;
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int length = 1; length <= (n - i) / 2; length++) {
            if (isEchoSubstring(text, i, length)) {
                char* substring = (char*)malloc((2 * length + 1) * sizeof(char));
                strncpy(substring, text + i, 2 * length);
                substring[2 * length] = '\\0';

                HashEntry* entry;
                HASH_FIND_STR(set, substring, entry);
                if (entry == NULL) {
                    entry = (HashEntry*)malloc(sizeof(HashEntry));
                    entry->key = substring;
                    HASH_ADD_KEYPTR(hh, set, entry->key, strlen(entry->key), entry);
                    count++;
                } else {
                    free(substring);
                }
            }
        }
    }

    HashEntry* current, *tmp;
    HASH_ITER(hh, set, current, tmp) {
        HASH_DEL(set, current);
        free(current->key);
        free(current);
    }

    return count;
}

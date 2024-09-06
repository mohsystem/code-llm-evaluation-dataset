code here:
// Note: This code assumes that the key and value are separated by a single '=' character
// and that there are no '=' characters in the key or value.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} Record;

int compare(const void* a, const void* b) {
    Record* ra = (Record*)a;
    Record* rb = (Record*)b;
    return strcmp(ra->key, rb->key);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        return 1;
    }
    Record records[100]; // assume max 100 records
    int count = 0;
    char line[1024];
    while (fgets(line, 1024, file)) {
        char* pos = strchr(line, '=');
        if (pos != NULL) {
            *pos = '\0';
            records[count].key = strdup(line);
            records[count].value = strdup(pos + 1);
            count++;
        }
    }
    qsort(records, count, sizeof(Record), compare);
    for (int i = 0; i < count; i++) {
        printf("%s=%s\n", records[i].key, records[i].value);
    }
    for (int i = 0; i < count; i++) {
        free(records[i].key);
        free(records[i].value);
    }
    fclose(file);
    return 0;
}
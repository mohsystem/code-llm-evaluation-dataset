// C code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SensitiveData {
    char *key;
    char *value;
    struct SensitiveData *next;
} SensitiveData;

SensitiveData* createNode(const char *key, const char *value) {
    SensitiveData *newNode = (SensitiveData*) malloc(sizeof(SensitiveData));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = NULL;
    return newNode;
}

void storeData(SensitiveData **head, const char *key, const char *value) {
    SensitiveData *newNode = createNode(key, value);
    newNode->next = *head;
    *head = newNode;
}

const char* retrieveData(SensitiveData *head, const char *key) {
    while (head != NULL) {
        if (strcmp(head->key, key) == 0) {
            return head->value;
        }
        head = head->next;
    }
    return "Data not found";
}

int main() {
    SensitiveData *head = NULL;
    storeData(&head, "credit_card", "1234-5678-9012-3456");
    printf("%s\n", retrieveData(head, "credit_card"));
    return 0;
}
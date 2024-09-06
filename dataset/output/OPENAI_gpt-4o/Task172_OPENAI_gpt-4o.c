#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char* str;
    struct Node* next;
} Node;

Node* createNode(char* str) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->str = strdup(str);
    node->next = NULL;
    return node;
}

int find(Node* head, char* str) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void insert(Node** head, char* str) {
    Node* new_node = createNode(str);
    new_node->next = *head;
    *head = new_node;
}

int distinctAASubstrings(char* text) {
    int n = strlen(text);
    Node* distinctSubstrings = NULL;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; j += 2) {
            int len = (j + 1 - i) / 2;
            char a[len + 1];
            char b[len + 1];
            strncpy(a, text + i, len);
            a[len] = '\0';
            strncpy(b, text + i + len, len);
            b[len] = '\0';
            if (strcmp(a, b) == 0) {
                char* substr = (char*)malloc((j - i + 2) * sizeof(char));
                strncpy(substr, text + i, j - i + 1);
                substr[j - i + 1] = '\0';
                if (!find(distinctSubstrings, substr)) {
                    insert(&distinctSubstrings, substr);
                    count++;
                }
            }
        }
    }

    Node* current = distinctSubstrings;
    while (current != NULL) {
        Node* next = current->next;
        free(current->str);
        free(current);
        current = next;
    }

    return count;
}

int main() {
    char text1[] = "abcabcabc";
    printf("%d\n", distinctAASubstrings(text1));

    char text2[] = "leetcodeleetcode";
    printf("%d\n", distinctAASubstrings(text2));

    return 0;
}
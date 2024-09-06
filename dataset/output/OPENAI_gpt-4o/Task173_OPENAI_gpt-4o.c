// C code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    long long hash;
    int index;
    struct Node *next;
} Node;

Node* createNode(long long hash, int index) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->hash = hash;
    newNode->index = index;
    newNode->next = NULL;
    return newNode;
}

bool findNode(Node* head, const char *s, int length, int current, char *result) {
    while (head) {
        if (strncmp(s + head->index, s + current, length) == 0) {
            strncpy(result, s + head->index, length);
            result[length] = '\0';
            return true;
        }
        head = head->next;
    }
    return false;
}

void addNode(Node** hashTable, long long hash, int index, int size) {
    int position = hash % size;
    Node* newNode = createNode(hash, index);
    newNode->next = hashTable[position];
    hashTable[position] = newNode;
}

long long rollHash(const char *s, int length) {
    const long long p = 31, m = (1LL << 61) - 1;
    long long hash_value = 0, p_pow = 1;
    for (int i = 0; i < length; ++i) {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void searchString(const char *s, int length, char *result) {
    const int size = 100003;
    Node* hashTable[size];
    for (int i = 0; i < size; ++i) hashTable[i] = NULL;
    
    const long long p = 31, m = (1LL << 61) - 1;
    long long p_pow = 1, currentHash = rollHash(s, length);
    for (int i = 1; i < length; ++i) p_pow = (p_pow * p) % m;
    
    addNode(hashTable, currentHash, 0, size);
    
    for (int i = 1; i <= strlen(s) - length; ++i) {
        currentHash = (currentHash - (s[i - 1] - 'a' + 1) * p_pow % m + m) % m;
        currentHash = (currentHash * p + (s[i + length - 1] - 'a' + 1)) % m;
        
        int position = currentHash % size;
        if (findNode(hashTable[position], s, length, i, result)) return;
        
        addNode(hashTable, currentHash, i, size);
    }
    result[0] = '\0';
}

void longestDupSubstring(const char *s, char *result) {
    int left = 1, right = strlen(s) - 1, mid;
    char tempResult[strlen(s)];
    
    while (left <= right) {
        mid = left + (right - left) / 2;
        searchString(s, mid, tempResult);
        
        if (tempResult[0] != '\0') {
            strcpy(result, tempResult);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
}

int main() {
    char result[10000];
    longestDupSubstring("banana", result);
    printf("%s\n", result);  // Output: "ana"
    longestDupSubstring("abcd", result);
    printf("%s\n", result);  // Output: ""
    return 0;
}
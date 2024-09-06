#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} SinglyLinkedList;

void initList(SinglyLinkedList* list) {
    list->head = NULL;
}

void insert(SinglyLinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (!list->head) {
        list->head = newNode;
    } else {
        Node* current = list->head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int delete(SinglyLinkedList* list, int data) {
    Node* current = list->head;
    Node* prev = NULL;
    while (current && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (!current) {
        return 0;
    }
    if (!prev) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return 1;
}

int search(SinglyLinkedList* list, int data) {
    Node* current = list->head;
    while (current) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    SinglyLinkedList list;
    initList(&list);
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    printf("%d\n", search(&list, 2));  // 1 (true)
    delete(&list, 2);
    printf("%d\n", search(&list, 2));  // 0 (false)
    return 0;
}
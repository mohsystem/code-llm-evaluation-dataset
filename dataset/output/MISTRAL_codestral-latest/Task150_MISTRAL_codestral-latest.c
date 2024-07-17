#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct SinglyLinkedList {
    Node* head;
} SinglyLinkedList;

void insert(SinglyLinkedList* list, int data) {
    if (list->head == NULL) {
        list->head = (Node*)malloc(sizeof(Node));
        list->head->data = data;
        list->head->next = NULL;
    } else {
        Node* cur = list->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = (Node*)malloc(sizeof(Node));
        cur->next->data = data;
        cur->next->next = NULL;
    }
}

void deleteNode(SinglyLinkedList* list, int data) {
    if (list->head == NULL) {
        return;
    }
    if (list->head->data == data) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    Node* cur = list->head;
    while (cur->next != NULL) {
        if (cur->next->data == data) {
            Node* temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
            return;
        }
        cur = cur->next;
    }
}

int search(SinglyLinkedList* list, int data) {
    Node* cur = list->head;
    while (cur != NULL) {
        if (cur->data == data) {
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}
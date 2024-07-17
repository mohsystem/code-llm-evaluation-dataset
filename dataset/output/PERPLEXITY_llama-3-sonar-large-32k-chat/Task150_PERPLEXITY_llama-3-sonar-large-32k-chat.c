#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[2];
    struct Node* next;
} Node;

void insert(Node** head, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(Node** head, char* data) {
    if (*head == NULL) {
        return;
    }

    if (strcmp((*head)->data, data) == 0) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node* current = *head;
    while (current->next) {
        if (strcmp(current->next->data, data) == 0) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

int search(Node* head, char* data) {
    Node* current = head;
    while (current) {
        if (strcmp(current->data, data) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%s ", current->data);
        current = current->next;
    }
    printf("
");
}

int main() {
    Node* head = NULL;
    insert(&head, "A");
    insert(&head, "B");
    insert(&head, "C");
    printList(head);  // Output: A B C
    deleteNode(&head, "B");
    printList(head);  // Output: A C
    printf("%d
", search(head, "C"));  // Output: 1
    printf("%d
", search(head, "B"));  // Output: 0
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

void insert(struct LinkedList* ll, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (ll->head == NULL) {
        ll->head = newNode;
    } else {
        struct Node* current = ll->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(struct LinkedList* ll, int data) {
    if (ll->head == NULL) {
        return;
    }

    if (ll->head->data == data) {
        struct Node* temp = ll->head;
        ll->head = ll->head->next;
        free(temp);
        return;
    }

    struct Node* current = ll->head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

int search(struct LinkedList* ll, int data) {
    struct Node* current = ll->head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void printList(struct LinkedList* ll) {
    struct Node* current = ll->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct LinkedList ll;
    ll.head = NULL;

    insert(&ll, 1);
    insert(&ll, 2);
    insert(&ll, 3);
    printList(&ll);  // Output: 1 2 3
    deleteNode(&ll, 2);
    printList(&ll);  // Output: 1 3
    printf("%d\n", search(&ll, 3));  // Output: 1
    printf("%d\n", search(&ll, 2));  // Output: 0
    return 0;
}
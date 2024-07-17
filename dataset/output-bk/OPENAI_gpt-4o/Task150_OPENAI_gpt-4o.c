#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct SinglyLinkedList {
    struct Node* head;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert(struct SinglyLinkedList* list, int data) {
    struct Node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        struct Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node(struct SinglyLinkedList* list, int key) {
    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        list->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int search(struct SinglyLinkedList* list, int key) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->data == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void display(struct SinglyLinkedList* list) {
    struct Node* current = list->head;
    printf("LinkedList: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("
");
}

int main() {
    struct SinglyLinkedList list;
    list.head = NULL;

    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    display(&list);
    delete_node(&list, 2);
    display(&list);
    printf("%d
", search(&list, 3));
    printf("%d
", search(&list, 2));

    return 0;
}
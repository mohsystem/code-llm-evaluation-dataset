#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    struct Node *head;
};

struct LinkedList *create_list() {
    struct LinkedList *list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    return list;
}

void insert(struct LinkedList *list, int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    struct Node *current_node = list->head;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
}

void delete(struct LinkedList *list, int data) {
    if (list->head == NULL) {
        return;
    }

    if (list->head->data == data) {
        list->head = list->head->next;
        return;
    }

    struct Node *current_node = list->head;
    struct Node *prev_node = NULL;
    while (current_node != NULL && current_node->data != data) {
        prev_node = current_node;
        current_node = current_node->next;
    }

    if (current_node == NULL) {
        return;
    }

    prev_node->next = current_node->next;
}

int search(struct LinkedList *list, int data) {
    struct Node *current_node = list->head;
    while (current_node != NULL && current_node->data != data) {
        current_node = current_node->next;
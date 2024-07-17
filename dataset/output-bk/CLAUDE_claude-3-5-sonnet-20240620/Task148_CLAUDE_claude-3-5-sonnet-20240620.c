
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack overflow\
");
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\
");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\
");
        return -1;
    }
    return s->items[s->top];
}

int size(Stack *s) {
    return s->top + 1;
}

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Top element: %d\
", peek(&stack));
    printf("Popped: %d\
", pop(&stack));
    printf("Size: %d\
", size(&stack));
    printf("Is empty: %s\
", isEmpty(&stack) ? "true" : "false");

    return 0;
}

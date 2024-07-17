#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef struct {
    int items[STACK_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int item) {
    if (s->top < STACK_SIZE - 1) {
        s->items[++(s->top)] = item;
    } else {
        printf("Stack overflow
");
    }
}

int pop(Stack *s) {
    if (s->top >= 0) {
        return s->items[(s->top)--];
    } else {
        printf("Stack underflow
");
        return -1;
    }
}

int peek(Stack *s) {
    if (s->top >= 0) {
        return s->items[s->top];
    } else {
        return -1;
    }
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int main() {
    Stack s;
    initialize(&s);
    push(&s, 10);
    push(&s, 20);
    printf("%d
", peek(&s));  // Output: 20
    printf("%d
", pop(&s));   // Output: 20
    printf("%d
", pop(&s));   // Output: 10
    printf("%d
", is_empty(&s));  // Output: 1 (true)
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void push(Stack *s, int item) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow
");
        return;
    }
    s->top++;
    s->items[s->top] = item;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow
");
        return -1;
    }
    int item = s->items[s->top];
    s->top--;
    return item;
}

int peek(Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty
");
        return -1;
    }
    return s->items[s->top];
}

int is_empty(Stack *s) {
    return s->top == -1;
}
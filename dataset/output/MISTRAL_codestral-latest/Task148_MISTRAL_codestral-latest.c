#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, int item) {
    if (stack->top >= MAX_SIZE - 1) {
        printf("Stack overflow
");
        return;
    }
    stack->items[++stack->top] = item;
}

int pop(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack underflow
");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

int peek(Stack *stack) {
    if (stack->top < 0) {
        printf("Stack is empty
");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top];
}
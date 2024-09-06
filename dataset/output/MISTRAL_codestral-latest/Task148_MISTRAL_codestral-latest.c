#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void push(Stack* stack, int item) {
    if (stack->top >= MAX_SIZE) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[stack->top++] = item;
}

int pop(Stack* stack) {
    if (stack->top <= 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->items[--stack->top];
}

int peek(Stack* stack) {
    if (stack->top <= 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top - 1];
}
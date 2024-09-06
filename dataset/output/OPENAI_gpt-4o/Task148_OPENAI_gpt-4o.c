#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int top;
    int maxSize;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->top = -1;
    stack->maxSize = size;
    return stack;
}

void push(Stack* stack, int item) {
    if (stack->top < stack->maxSize - 1) {
        stack->items[++stack->top] = item;
    } else {
        printf("Stack Overflow!\n");
    }
}

int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    }
    printf("Stack Underflow!\n");
    return -1;
}

int peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top];
    }
    printf("Stack is Empty!\n");
    return -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

int main() {
    Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("%d\n", pop(stack));  // Output: 3
    printf("%d\n", peek(stack));  // Output: 2
    free(stack->items);
    free(stack);
    return 0;
}
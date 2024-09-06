#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef struct {
    int maxSize;
    int top;
    int* stackArray;
} Stack;

Stack* createStack(int size) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->maxSize = size;
    stack->top = -1;
    stack->stackArray = (int*) malloc(size * sizeof(int));
    return stack;
}

void push(Stack* stack, int item) {
    if (stack->top >= stack->maxSize - 1) {
        printf("Stack is full. Can't push %d\n", item);
        return;
    }
    stack->stackArray[++stack->top] = item;
}

int pop(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty. Can't pop.\n");
        return -1;
    }
    return stack->stackArray[stack->top--];
}

int peek(Stack* stack) {
    if (stack->top < 0) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->stackArray[stack->top];
}

int isEmpty(Stack* stack) {
    return (stack->top == -1);
}

int main() {
    Stack* stack = createStack(MAX_SIZE);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("%d\n", pop(stack));  // Output: 3
    printf("%d\n", peek(stack));  // Output: 2
    return 0;
}
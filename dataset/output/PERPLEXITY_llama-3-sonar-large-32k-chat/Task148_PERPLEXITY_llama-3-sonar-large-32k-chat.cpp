#include <iostream>

class Stack {
private:
    int maxSize;
    int top;
    int* stackArray;

public:
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    void push(int item) {
        if (top >= maxSize - 1) {
            std::cout << "Stack is full. Can't push " << item << std::endl;
            return;
        }
        stackArray[++top] = item;
    }

    int pop() {
        if (top < 0) {
            std::cout << "Stack is empty. Can't pop." << std::endl;
            return -1;
        }
        return stackArray[top--];
    }

    int peek() {
        if (top < 0) {
            std::cout << "Stack is empty." << std::endl;
            return -1;
        }
        return stackArray[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    Stack stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.pop() << std::endl;  // 3
    std::cout << stack.peek() << std::endl;  // 2
    std::cout << std::boolalpha << stack.isEmpty() << std::endl;  // false
    return 0;
}
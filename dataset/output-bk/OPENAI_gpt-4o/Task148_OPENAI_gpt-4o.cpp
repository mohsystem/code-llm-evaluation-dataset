#include <iostream>
#include <vector>

class Stack {
    std::vector<int> stack;

public:
    void push(int item) {
        stack.push_back(item);
    }

    int pop() {
        if (!isEmpty()) {
            int item = stack.back();
            stack.pop_back();
            return item;
        }
        return -1;  // Return -1 if stack is empty
    }

    int peek() {
        if (!isEmpty()) {
            return stack.back();
        }
        return -1;  // Return -1 if stack is empty
    }

    bool isEmpty() {
        return stack.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << s.peek() << std::endl;  // Output: 20
    std::cout << s.pop() << std::endl;   // Output: 20
    std::cout << s.pop() << std::endl;   // Output: 10
    std::cout << s.isEmpty() << std::endl;  // Output: 1 (true)
    return 0;
}
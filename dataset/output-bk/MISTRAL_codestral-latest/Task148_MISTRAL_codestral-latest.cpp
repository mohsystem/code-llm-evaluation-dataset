#include <stack>
#include <stdexcept>

class MyStack {
private:
    std::stack<int> stack;

public:
    void push(int item) {
        stack.push(item);
    }

    int pop() {
        if (stack.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        int item = stack.top();
        stack.pop();
        return item;
    }

    int peek() {
        if (stack.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return stack.top();
    }
};
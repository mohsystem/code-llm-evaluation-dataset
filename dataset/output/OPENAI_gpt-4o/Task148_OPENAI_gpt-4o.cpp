#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack;
public:
    void push(int item) {
        stack.push_back(item);
    }

    int pop() {
        if (!is_empty()) {
            int item = stack.back();
            stack.pop_back();
            return item;
        }
        return -1; // Assuming -1 is returned when stack is empty
    }

    int peek() {
        if (!is_empty()) {
            return stack.back();
        }
        return -1; // Assuming -1 is returned when stack is empty
    }

    bool is_empty() {
        return stack.empty();
    }
};

int main() {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << stack.pop() << std::endl;  // Output: 3
    std::cout << stack.peek() << std::endl;  // Output: 2
    return 0;
}
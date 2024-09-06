
#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> items;

public:
    void push(T item) {
        items.push_back(item);
    }

    T pop() {
        if (!isEmpty()) {
            T item = items.back();
            items.pop_back();
            return item;
        }
        return T();
    }

    T peek() {
        if (!isEmpty()) {
            return items.back();
        }
        return T();
    }

    bool isEmpty() {
        return items.empty();
    }

    size_t size() {
        return items.size();
    }
};

int main() {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Top element: " << stack.peek() << std::endl;
    std::cout << "Popped: " << stack.pop() << std::endl;
    std::cout << "Size: " << stack.size() << std::endl;
    return 0;
}

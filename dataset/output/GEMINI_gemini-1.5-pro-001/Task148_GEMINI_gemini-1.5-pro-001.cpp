#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> items;

public:
    void push(T item) {
        items.push_back(item);
    }

    T pop() {
        if (!is_empty()) {
            T item = items.back();
            items.pop_back();
            return item;
        } else {
            throw runtime_error("Stack is empty");
        }
    }

    T peek() {
        if (!is_empty()) {
            return items.back();
        } else {
            throw runtime_error("Stack is empty");
        }
    }

    bool is_empty() {
        return items.empty();
    }
};

#include <iostream>
#include <queue>

template <typename T>
class Queue {
private:
    std::queue<T> items;

public:
    void enqueue(T item) {
        items.push(item);
    }

    T dequeue() {
        if (!isEmpty()) {
            T front = items.front();
            items.pop();
            return front;
        }
        return T();
    }

    T peek() {
        if (!isEmpty()) {
            return items.front();
        }
        return T();
    }

    bool isEmpty() {
        return items.empty();
    }

    int size() {
        return items.size();
    }
};

int main() {
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << q.peek() << std::endl;  // Output: 1
    std::cout << q.dequeue() << std::endl;  // Output: 1
    std::cout << q.size() << std::endl;  // Output: 2
    return 0;
}

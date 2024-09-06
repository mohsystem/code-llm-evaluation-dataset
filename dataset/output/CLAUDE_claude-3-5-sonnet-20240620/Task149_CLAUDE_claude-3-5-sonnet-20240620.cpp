
#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> items;

public:
    bool isEmpty() {
        return items.empty();
    }

    void enqueue(int item) {
        items.push(item);
    }

    int dequeue() {
        if (!isEmpty()) {
            int front = items.front();
            items.pop();
            return front;
        }
        return -1;  // Assuming -1 as an invalid value
    }

    int peek() {
        if (!isEmpty()) {
            return items.front();
        }
        return -1;  // Assuming -1 as an invalid value
    }
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    std::cout << queue.peek() << std::endl;  // Output: 1
    std::cout << queue.dequeue() << std::endl;  // Output: 1
    std::cout << queue.dequeue() << std::endl;  // Output: 2
    std::cout << queue.isEmpty() << std::endl;  // Output: 0 (false)
    std::cout << queue.dequeue() << std::endl;  // Output: 3
    std::cout << queue.isEmpty() << std::endl;  // Output: 1 (true)

    return 0;
}

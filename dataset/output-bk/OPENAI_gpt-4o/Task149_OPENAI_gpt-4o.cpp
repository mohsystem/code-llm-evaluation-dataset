#include <iostream>
#include <queue>

class Queue {
public:
    void enqueue(int item) {
        q.push(item);
    }

    int dequeue() {
        if (!q.empty()) {
            int item = q.front();
            q.pop();
            return item;
        }
        return -1;  // Indicates that the queue is empty
    }

    int peek() {
        if (!q.empty()) {
            return q.front();
        }
        return -1;  // Indicates that the queue is empty
    }

    bool is_empty() {
        return q.empty();
    }

private:
    std::queue<int> q;
};

// Test the queue
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    std::cout << q.peek() << std::endl;  // Output: 1
    std::cout << q.dequeue() << std::endl;  // Output: 1
    std::cout << q.dequeue() << std::endl;  // Output: 2
    q.enqueue(4);
    std::cout << q.peek() << std::endl;  // Output: 3
    std::cout << q.dequeue() << std::endl;  // Output: 3
    std::cout << q.dequeue() << std::endl;  // Output: 4
    return 0;
}
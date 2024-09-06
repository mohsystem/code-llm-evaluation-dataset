#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> queue;

public:
    void enqueue(int item) {
        queue.push(item);
    }

    int dequeue() {
        if (!queue.empty()) {
            int front = queue.front();
            queue.pop();
            return front;
        }
        return -1; // Indicator for empty queue
    }

    int peek() {
        if (!queue.empty()) {
            return queue.front();
        }
        return -1; // Indicator for empty queue
    }

    bool isEmpty() {
        return queue.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    std::cout << q.dequeue() << std::endl;  // 10
    std::cout << q.peek() << std::endl;  // 20
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

class Queue {
private:
    std::vector<std::string> queue;
    int front, rear, size, capacity;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        this->queue.resize(capacity);
        this->front = this->rear = this->size = 0;
    }

    void enqueue(std::string item) {
        if (size == capacity) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        queue[rear] = item;
        rear = (rear + 1) % capacity;
        size++;
    }

    std::string dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return "";
        }
        std::string item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    std::string peek() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return "";
        }
        return queue[front];
    }
};

int main() {
    Queue q(5);
    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Cherry");
    std::cout << q.dequeue() << std::endl;  // Apple
    std::cout << q.peek() << std::endl;  // Banana
    return 0;
}
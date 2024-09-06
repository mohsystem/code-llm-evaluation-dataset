#include <iostream>
#include <queue>
#include <string>

class Queue {
private:
    std::queue<std::string> queue;

public:
    void enqueue(const std::string& item) {
        queue.push(item);
    }

    std::string dequeue() {
        if (queue.empty()) {
            return "";
        }
        std::string item = queue.front();
        queue.pop();
        return item;
    }

    std::string peek() {
        if (queue.empty()) {
            return "";
        }
        return queue.front();
    }
};

int main() {
    Queue q;
    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Cherry");
    std::cout << q.dequeue() << std::endl;  // Apple
    std::cout << q.peek() << std::endl;  // Banana
    return 0;
}
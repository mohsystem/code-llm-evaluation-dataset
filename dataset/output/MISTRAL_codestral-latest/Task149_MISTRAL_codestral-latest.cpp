#include <queue>

class Queue {
    std::queue<int> q;

public:
    // Add an element
    void enqueue(int item) {
        q.push(item);
    }

    // Remove an element
    int dequeue() {
        if (q.empty()) {
            return -1; // or throw an exception
        }
        int item = q.front();
        q.pop();
        return item;
    }

    // Display the front element
    int peek() {
        if (q.empty()) {
            return -1; // or throw an exception
        }
        return q.front();
    }
};
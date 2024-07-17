#include <queue>

class Queue {
    private:
        std::queue<int> queue;

    public:
        void enqueue(int item) {
            queue.push(item);
        }

        int dequeue() {
            if (queue.empty()) {
                return -1;
            }
            int item = queue.front();
            queue.pop();
            return item;
        }

        int peek() {
            if (queue.empty()) {
                return -1;
            }
            return queue.front();
        }
};
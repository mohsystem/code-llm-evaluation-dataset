#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int>> large;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (small.size() == large.size()) {
            small.push(num);
            large.push(small.top());
            small.pop();
        } else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() == large.size()) {
            return (small.top() + large.top()) / 2.0;
        } else {
            return small.top();
        }
    }
};
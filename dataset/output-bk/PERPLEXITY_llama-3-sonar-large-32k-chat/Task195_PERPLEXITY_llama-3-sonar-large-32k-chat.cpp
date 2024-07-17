#include <queue>

class MedianFinder {
private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;

public:
    MedianFinder() {}

    void addNum(int num) {
        if (lower.empty() || num <= lower.top()) {
            lower.push(num);
        } else {
            higher.push(num);
        }
        
        if (lower.size() > higher.size() + 1) {
            higher.push(lower.top());
            lower.pop();
        } else if (higher.size() > lower.size()) {
            lower.push(higher.top());
            higher.pop();
        }
    }

    double findMedian() {
        if (lower.size() == higher.size()) {
            return (lower.top() + higher.top()) / 2.0;
        } else {
            return lower.top();
        }
    }
};
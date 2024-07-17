
#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> small;  // max heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> large;  // min heap

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
            return large.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

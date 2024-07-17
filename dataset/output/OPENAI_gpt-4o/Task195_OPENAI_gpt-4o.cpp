#include <iostream>
#include <queue>
#include <vector>

class MedianFinder {
private:
    std::priority_queue<int> small;
    std::priority_queue<int, std::vector<int>, std::greater<int>> large;

public:
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return small.top();
        }
        return (small.top() + large.top()) / 2.0;
    }
};

int main() {
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    std::cout << medianFinder.findMedian() << std::endl; // Output: 1.5
    medianFinder.addNum(3);
    std::cout << medianFinder.findMedian() << std::endl; // Output: 2.0
    return 0;
}
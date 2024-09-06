#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
public:
    priority_queue<int> small;              // Max-heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> large; // Min-heap (stores larger half)

    MedianFinder() {}

    void addNum(int num) {
        small.push(num); // Add to small heap

        // Balance heaps
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }

        // Adjust heaps if needed
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            large.push(small.top());
            small.pop();
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        if (small.size() > large.size()) {
            return (double) small.top();
        } else {
            return (double) (small.top() + large.top()) / 2;
        }
    }
};
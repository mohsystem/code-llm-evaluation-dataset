#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> small;            // Max-heap (left side)
    priority_queue<int, vector<int>, greater<int>> large; // Min-heap (right side)

    MedianFinder() { }

    void addNum(int num) {
        small.push(num); 

        // Balance the heaps: ensure size(small) - 1 <= size(large)
        if (small.size() > large.size() + 1) {
            large.push(small.top());
            small.pop();
        }

        // Further balancing: ensure max(small) <= min(large)
        if (!small.empty() && !large.empty() && small.top() > large.top()) {
            int valSmall = small.top();
            int valLarge = large.top();
            small.pop();
            large.pop();
            small.push(valLarge);
            large.push(valSmall);
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
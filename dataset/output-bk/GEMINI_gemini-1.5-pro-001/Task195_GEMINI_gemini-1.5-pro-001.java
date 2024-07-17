import java.util.PriorityQueue;

class MedianFinder {
    private PriorityQueue<Integer> small;  // Max-heap (left side)
    private PriorityQueue<Integer> large;  // Min-heap (right side)

    public MedianFinder() {
        small = new PriorityQueue<>((a, b) -> b - a);  // Lambda for max-heap
        large = new PriorityQueue<>();
    }

    public void addNum(int num) {
        small.offer(num); // Add to max-heap

        // Balance the heaps: ensure size(small) - 1 <= size(large)
        if (small.size() > large.size() + 1) {
            large.offer(small.poll());
        }

        // Further balancing: ensure max(small) <= min(large)
        if (!small.isEmpty() && !large.isEmpty() && small.peek() > large.peek()) {
            int valSmall = small.poll();
            int valLarge = large.poll();
            small.offer(valLarge);
            large.offer(valSmall);
        }
    }

    public double findMedian() {
        if (small.size() > large.size()) {
            return (double) small.peek();
        } else {
            return (double) (small.peek() + large.peek()) / 2;
        }
    }
}
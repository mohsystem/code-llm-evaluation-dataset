import java.util.PriorityQueue;

class MedianFinder {
    private PriorityQueue<Integer> small; // Max-heap (stores smaller half)
    private PriorityQueue<Integer> large; // Min-heap (stores larger half)

    public MedianFinder() {
        small = new PriorityQueue<>((a, b) -> b - a); // Lambda for max-heap
        large = new PriorityQueue<>();
    }

    public void addNum(int num) {
        small.offer(num); // Add to small heap

        // Balance heaps
        if (small.size() > large.size() + 1) {
            large.offer(small.poll());
        }

        // Adjust heaps if needed
        if (!small.isEmpty() && !large.isEmpty() && small.peek() > large.peek()) {
            large.offer(small.poll());
            small.offer(large.poll());
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
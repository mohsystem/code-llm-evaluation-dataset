import java.util.*;

class MedianFinder {
    private PriorityQueue<Integer> lower;
    private PriorityQueue<Integer> higher;

    public MedianFinder() {
        lower = new PriorityQueue<>((a, b) -> b - a);
        higher = new PriorityQueue<>();
    }

    public void addNum(int num) {
        if (lower.isEmpty() || num <= lower.peek()) {
            lower.offer(num);
        } else {
            higher.offer(num);
        }
        
        if (lower.size() > higher.size() + 1) {
            higher.offer(lower.poll());
        } else if (higher.size() > lower.size()) {
            lower.offer(higher.poll());
        }
    }

    public double findMedian() {
        if (lower.size() == higher.size()) {
            return (lower.peek() + higher.peek()) / 2.0;
        } else {
            return lower.peek();
        }
    }
}
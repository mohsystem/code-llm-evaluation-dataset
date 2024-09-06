import java.util.LinkedList;
import java.util.Queue;

public class Task149_MISTRAL_codestral_latest {
    Queue<Integer> queue = new LinkedList<>();

    // Add an element
    public void enqueue(int item) {
        queue.add(item);
    }

    // Remove an element
    public Integer dequeue() {
        if (queue.isEmpty()) {
            return null;
        }
        return queue.poll();
    }

    // Display the front element
    public Integer peek() {
        if (queue.isEmpty()) {
            return null;
        }
        return queue.peek();
    }
}
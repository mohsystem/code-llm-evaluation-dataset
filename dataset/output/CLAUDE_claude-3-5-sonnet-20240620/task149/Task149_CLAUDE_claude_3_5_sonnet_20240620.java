
import java.util.LinkedList;

public class Task149_CLAUDE_claude_3_5_sonnet_20240620<T> {
    private LinkedList<T> items;

    public Task149_CLAUDE_claude_3_5_sonnet_20240620() {
        items = new LinkedList<>();
    }

    public boolean isEmpty() {
        return items.isEmpty();
    }

    public void enqueue(T item) {
        items.addLast(item);
    }

    public T dequeue() {
        if (!isEmpty()) {
            return items.removeFirst();
        }
        return null;
    }

    public T peek() {
        if (!isEmpty()) {
            return items.getFirst();
        }
        return null;
    }

    public static void main(String[] args) {
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);

        System.out.println(queue.peek());  // Output: 1
        System.out.println(queue.dequeue());  // Output: 1
        System.out.println(queue.dequeue());  // Output: 2
        System.out.println(queue.isEmpty());  // Output: false
        System.out.println(queue.dequeue());  // Output: 3
        System.out.println(queue.isEmpty());  // Output: true
    }
}

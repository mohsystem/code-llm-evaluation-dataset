
import java.util.LinkedList;

public class Queue<T> {
    private LinkedList<T> items;

    public Queue() {
        items = new LinkedList<>();
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

    public boolean isEmpty() {
        return items.isEmpty();
    }

    public int size() {
        return items.size();
    }

    public static void main(String[] args) {
        Queue<Integer> q = new Queue<>();
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        System.out.println(q.peek());  // Output: 1
        System.out.println(q.dequeue());  // Output: 1
        System.out.println(q.size());  // Output: 2
    }
}

import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> queue = new LinkedList<>();

        queue.add(1);
        queue.add(2);
        queue.add(3);
        System.out.println(queue.peek());  // Output: 1
        System.out.println(queue.remove());  // Output: 1
        System.out.println(queue.remove());  // Output: 2
        queue.add(4);
        System.out.println(queue.peek());  // Output: 3
        System.out.println(queue.remove());  // Output: 3
        System.out.println(queue.remove());  // Output: 4
    }
}
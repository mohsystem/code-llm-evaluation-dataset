import java.util.LinkedList;

class Queue {
    private LinkedList<Integer> queue = new LinkedList<>();

    public void enqueue(int item) {
        queue.addLast(item);
    }

    public int dequeue() {
        if (!queue.isEmpty()) {
            return queue.removeFirst();
        }
        return -1;
    }

    public int peek() {
        if (!queue.isEmpty()) {
            return queue.getFirst();
        }
        return -1;
    }

    public boolean isEmpty() {
        return queue.isEmpty();
    }

    public static void main(String[] args) {
        Queue q = new Queue();
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        System.out.println(q.dequeue());  // 10
        System.out.println(q.peek());  // 20
    }
}
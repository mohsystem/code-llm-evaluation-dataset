class Queue {
    private java.util.ArrayList<String> queue;

    public Queue() {
        queue = new java.util.ArrayList<String>();
    }

    public void enqueue(String item) {
        queue.add(item);
    }

    public String dequeue() {
        if (queue.size() < 1) {
            return null;
        }
        return queue.remove(0);
    }

    public String peek() {
        if (queue.size() < 1) {
            return null;
        }
        return queue.get(0);
    }

    public static void main(String[] args) {
        Queue q = new Queue();
        q.enqueue("Apple");
        q.enqueue("Banana");
        q.enqueue("Cherry");
        System.out.println(q.dequeue());  // Apple
        System.out.println(q.peek());  // Banana
    }
}
class Queue {
    private String[] queue;
    private int front, rear, size, capacity;

    public Queue(int capacity) {
        this.capacity = capacity;
        this.queue = new String[capacity];
        this.front = this.rear = this.size = 0;
    }

    public void enqueue(String item) {
        if (size == capacity) {
            System.out.println("Queue is full");
            return;
        }
        queue[rear] = item;
        rear = (rear + 1) % capacity;
        size++;
    }

    public String dequeue() {
        if (size == 0) {
            System.out.println("Queue is empty");
            return null;
        }
        String item = queue[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    public String peek() {
        if (size == 0) {
            System.out.println("Queue is empty");
            return null;
        }
        return queue[front];
    }

    public static void main(String[] args) {
        Queue q = new Queue(5);
        q.enqueue("Apple");
        q.enqueue("Banana");
        q.enqueue("Cherry");
        System.out.println(q.dequeue());  // Apple
        System.out.println(q.peek());  // Banana
    }
}
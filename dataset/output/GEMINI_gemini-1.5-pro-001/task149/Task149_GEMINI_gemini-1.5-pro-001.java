class Node {
    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}

class Queue {
    Node front, rear;

    public Queue()
    {
        front = rear = null;
    }

    void enqueue(int d)
    {
        Node newNode = new Node(d);

        if (rear == null) {
            front = rear = newNode;
            return;
        }
        rear.next = newNode;
        rear = newNode;
    }

    int dequeue()
    {
        if (front == null)
            return Integer.MIN_VALUE;
        Node temp = front;
        front = temp.next;
        if (front == null)
            rear = null;
        return temp.data;
    }

    int peek()
    {
        if (front == null)
            return Integer.MIN_VALUE;
        return front.data;
    }

    
}
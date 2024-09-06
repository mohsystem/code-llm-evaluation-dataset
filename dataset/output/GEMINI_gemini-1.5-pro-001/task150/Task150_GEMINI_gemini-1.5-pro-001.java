class Node {
    int data;
    Node next;

    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkedList {
    Node head;

    public void insert(int data) {
        Node new_node = new Node(data);
        if (head == null) {
            head = new_node;
            return;
        }

        Node current_node = head;
        while (current_node.next != null) {
            current_node = current_node.next;
        }

        current_node.next = new_node;
    }

    public void delete(int data) {
        if (head == null) {
            return;
        }

        if (head.data == data) {
            head = head.next;
            return;
        }

        Node current_node = head;
        Node prev_node = null;
        while (current_node != null && current_node.data != data) {
            prev_node = current_node;
            current_node = current_node.next;
        }

        if (current_node == null) {
            return;
        }

        prev_node.next = current_node.next;
    }

    public boolean search(int data) {
        Node current_node = head;
        while (current_node != null && current_node.data != data) {
            current_node = current_node.next;
        }

        if (current_node == null) {
            return false;
        }

        return true;
    }

    public void printList() {
        Node current_node = head;
        while (current_node != null) {
            System.out.print(current_node.data + " ");
            current_node = current_node.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.insert(1);
        ll.insert(2);
        ll.insert(3);
        ll.insert(4);
        ll.insert(5);
        ll.printList();
        ll.delete(3);
        ll.printList();
        System.out.println(ll.search(4));
    }
}
// Java code
public class Task150_MISTRAL_codestral_latest {
    int data;
    Task150_MISTRAL_codestral_latest next;

    Task150_MISTRAL_codestral_latest(int data) {
        this.data = data;
        this.next = null;
    }
}

public class SinglyLinkedList {
    Task150_MISTRAL_codestral_latest head;

    public void insert(int data) {
        if (head == null) {
            head = new Task150_MISTRAL_codestral_latest(data);
        } else {
            Task150_MISTRAL_codestral_latest current = head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = new Task150_MISTRAL_codestral_latest(data);
        }
    }

    public void delete(int data) {
        if (head == null) {
            return;
        }
        if (head.data == data) {
            head = head.next;
            return;
        }
        Task150_MISTRAL_codestral_latest current = head;
        while (current.next != null) {
            if (current.next.data == data) {
                current.next = current.next.next;
                return;
            }
            current = current.next;
        }
    }

    public boolean search(int data) {
        Task150_MISTRAL_codestral_latest current = head;
        while (current != null) {
            if (current.data == data) {
                return true;
            }
            current = current.next;
        }
        return false;
    }
}
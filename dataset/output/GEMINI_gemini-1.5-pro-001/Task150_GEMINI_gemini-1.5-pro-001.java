import java.util.Scanner;

public class SinglyLinkedList {

    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    Node head;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        SinglyLinkedList list = new SinglyLinkedList();

        while (true) {
            System.out.println("
Singly Linked List Operations:");
            System.out.println("1. Insert");
            System.out.println("2. Delete");
            System.out.println("3. Search");
            System.out.println("4. Print");
            System.out.println("5. Exit");

            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the data to insert: ");
                    int data = scanner.nextInt();
                    list.insert(data);
                    break;
                case 2:
                    System.out.print("Enter the data to delete: ");
                    int deleteData = scanner.nextInt();
                    list.delete(deleteData);
                    break;
                case 3:
                    System.out.print("Enter the data to search: ");
                    int searchData = scanner.nextInt();
                    Node foundNode = list.search(searchData);
                    if (foundNode != null) {
                        System.out.println("Data found in the list.");
                    } else {
                        System.out.println("Data not found in the list.");
                    }
                    break;
                case 4:
                    list.printList();
                    break;
                case 5:
                    System.out.println("Exiting program...");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice! Please try again.");
            }
        }
    }

    // Insert a new node at the beginning of the list
    public void insert(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
        System.out.println("Data inserted successfully.");
    }

    // Delete a node with the given data
    public void delete(int data) {
        Node currNode = head;
        Node prevNode = null;

        // If the head node needs to be deleted
        if (currNode != null && currNode.data == data) {
            head = currNode.next;
            System.out.println("Data deleted successfully.");
            return;
        }

        // Search for the node to be deleted
        while (currNode != null && currNode.data != data) {
            prevNode = currNode;
            currNode = currNode.next;
        }

        // If the node is found
        if (currNode != null) {
            prevNode.next = currNode.next;
            System.out.println("Data deleted successfully.");
        } else {
            System.out.println("Data not found in the list.");
        }
    }

    // Search for a node with the given data
    public Node search(int data) {
        Node currNode = head;

        while (currNode != null) {
            if (currNode.data == data) {
                return currNode;
            }
            currNode = currNode.next;
        }

        return null; // Data not found
    }

    // Print the linked list
    public void printList() {
        Node currNode = head;

        System.out.print("Linked List: ");

        while (currNode != null) {
            System.out.print(currNode.data + " ");
            currNode = currNode.next;
        }

        System.out.println();
    }
}
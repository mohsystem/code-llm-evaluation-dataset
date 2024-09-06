#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
public:
    LinkedList() {
        head = NULL;
    }

    void insert(int data) {
        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            return;
        }

        Node *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }

        current_node->next = new_node;
    }

    void delete(int data) {
        if (head == NULL) {
            return;
        }

        if (head->data == data) {
            head = head->next;
            return;
        }

        Node *current_node = head;
        Node *prev_node = NULL;
        while (current_node != NULL && current_node->data != data) {
            prev_node = current_node;
            current_node = current_node->next;
        }

        if (current_node == NULL) {
            return;
        }

        prev_node->next = current_node->next;
    }

    bool search(int data) {
        Node *current_node = head;
        while (current_node != NULL && current_node->data != data) {
            current_node = current_node->next;
        }

        if (current_node == NULL) {
            return false;
        }

        return true;
    }

    void printList() {
        Node *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }

        cout << endl;
    }

private:
    Node *head;
};

int main() {
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    ll.printList();
    ll.delete(3);
    ll.printList();
    cout << ll.search(4) << endl;

    return 0;
}
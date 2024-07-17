#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(string data) {
        if (!head) {
            head = new Node(data);
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(data);
        }
    }

    void deleteNode(string data) {
        if (!head) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    bool search(string data) {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printList() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    ll.insert("A");
    ll.insert("B");
    ll.insert("C");
    ll.printList();  // Output: A B C
    ll.deleteNode("B");
    ll.printList();  // Output: A C
    cout << (ll.search("C") ? "true" : "false") << endl;  // Output: true
    cout << (ll.search("B") ? "true" : "false") << endl;  // Output: false
    return 0;
}
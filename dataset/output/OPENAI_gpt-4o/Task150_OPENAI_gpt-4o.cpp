#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    bool deleteNode(int data) {
        Node* current = head;
        Node* prev = nullptr;
        while (current && current->data != data) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            return false;
        }
        if (!prev) {
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        return true;
    }

    bool search(int data) {
        Node* current = head;
        while (current) {
            if (current->data == data) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insert(1);
    sll.insert(2);
    sll.insert(3);
    std::cout << sll.search(2) << std::endl;  // 1 (true)
    sll.deleteNode(2);
    std::cout << sll.search(2) << std::endl;  // 0 (false)
    return 0;
}
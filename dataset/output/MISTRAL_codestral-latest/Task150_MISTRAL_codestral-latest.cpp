#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int data) {
        if (head == nullptr) {
            head = new Node{data, nullptr};
        } else {
            Node* cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new Node{data, nullptr};
        }
    }

    void deleteNode(int data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr) {
            if (cur->next->data == data) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return;
            }
            cur = cur->next;
        }
    }

    bool search(int data) {
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data == data) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};
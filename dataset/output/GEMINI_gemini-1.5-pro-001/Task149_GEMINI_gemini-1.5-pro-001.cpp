#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
public:
    Node *front, *rear;
    Queue() { 
        front = rear = NULL; 
    }
    void enqueue(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == NULL)
            return;
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete (temp);
    }

    int peek() {
        if (front == NULL){
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
};
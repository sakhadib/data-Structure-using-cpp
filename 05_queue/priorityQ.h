#include <iostream>
using namespace std;

class PriorityQueue {
private:
    class Node {
    public:
        int data;
        int priority;
        Node* next;

        Node(int data, int priority) {
            this->data = data;
            this->priority = priority;
            next = nullptr;
        }
    };

    Node* front;

public:
    PriorityQueue() {
        front = nullptr;
    }

    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        if (front == nullptr || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Priority queue is empty." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        if (front == nullptr) {
            cout << "Priority queue is empty." << endl;
        } else {
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

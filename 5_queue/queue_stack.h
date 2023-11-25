#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
    stack<int> inStack;
    stack<int> outStack;

public:
    Queue() {}

    void enqueue(int value) {
        inStack.push(value);
    }

    int dequeue() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        int front = outStack.top();
        outStack.pop();
        return front;
    }

    int front() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }

        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Front element: " << q.front() << endl;

    return 0;
}

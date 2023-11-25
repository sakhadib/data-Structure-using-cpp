#include <iostream>
using namespace std;
const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    int arr[MAX_SIZE]; // Array to store stack elements
    int top; // Index of the top element

public:
    Stack() {
        top = -1; // Initialize the top index to -1
    }

    bool isEmpty() {
        return (top == -1); // Check if the stack is empty
    }

    bool isFull() {
        return (top == MAX_SIZE - 1); // Check if the stack is full
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        arr[++top] = value; // Increment top and insert the value
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }

        return arr[top--]; // Decrement top and return the top element
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }

        return arr[top]; // Return the top element without removing it
    }
};

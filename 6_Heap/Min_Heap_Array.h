
#include <iostream>

using namespace std;

class MinHeap {
private:
    int* heapArray;
    int capacity;
    int size;

public:
    MinHeap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->heapArray = new int[capacity];
    }

    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        size++;
        int i = size - 1;
        heapArray[i] = value;

        while (i != 0 && heapArray[parent(i)] > heapArray[i]) {
            swap(heapArray[i], heapArray[parent(i)]);
            i = parent(i);
        }
    }

    void removeMin() {
        if (size <= 0) {
            cout << "Heap is empty. Cannot remove minimum element." << endl;
            return;
        }

        if (size == 1) {
            size--;
            return;
        }

        int root = heapArray[0];
        heapArray[0] = heapArray[size - 1];
        size--;
        heapify(0);
    }

    int getMin() {
        if (size <= 0) {
            cout << "Heap is empty." << endl;
            return -1;
        }

        return heapArray[0];
    }

private:
    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return (2 * i) + 1;
    }

    int rightChild(int i) {
        return (2 * i) + 2;
    }

    void heapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heapArray[left] < heapArray[smallest]) {
            smallest = left;
        }

        if (right < size && heapArray[right] < heapArray[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heapArray[i], heapArray[smallest]);
            heapify(smallest);
        }
    }
};

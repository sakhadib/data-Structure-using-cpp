#include <iostream>

using namespace std;

class MaxHeap {
private:
    int* heapArray;
    int maxSize;
    int currentSize;

public:
    MaxHeap(int size) {
        maxSize = size;
        currentSize = 0;
        heapArray = new int[maxSize];
    }

    ~MaxHeap() {
        delete[] heapArray;
    }

    void insert(int value) {
        if (currentSize == maxSize) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        int currentIndex = currentSize;
        heapArray[currentIndex] = value;

        while (currentIndex > 0 && heapArray[currentIndex] > heapArray[parentIndex(currentIndex)]) {
            swap(heapArray[currentIndex], heapArray[parentIndex(currentIndex)]);
            currentIndex = parentIndex(currentIndex);
        }

        currentSize++;
    }

    void removeMax() {
        if (currentSize == 0) {
            cout << "Heap is empty. Cannot remove any element." << endl;
            return;
        }

        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;

        heapify(0);
    }

    void heapify(int index) {
        int largest = index;
        int leftChild = leftChildIndex(index);
        int rightChild = rightChildIndex(index);

        if (leftChild < currentSize && heapArray[leftChild] > heapArray[largest]) {
            largest = leftChild;
        }

        if (rightChild < currentSize && heapArray[rightChild] > heapArray[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heapArray[index], heapArray[largest]);
            heapify(largest);
        }
    }

    void printHeap() {
        for (int i = 0; i < currentSize; i++) {
            cout << heapArray[i] << " ";
        }
        cout << endl;
    }

private:
    int parentIndex(int index) {
        return (index - 1) / 2;
    }

    int leftChildIndex(int index) {
        return (2 * index) + 1;
    }

    int rightChildIndex(int index) {
        return (2 * index) + 2;
    }
};


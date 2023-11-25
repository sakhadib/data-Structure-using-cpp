#include <iostream>
using namespace std;

class BinaryTree {
private:
    int* treeArray;
    int size;

public:
    BinaryTree(int maxSize) {
        size = maxSize + 1; // Adding 1 to the size to ignore index 0
        treeArray = new int[size];
        for (int i = 0; i < size; i++) {
            treeArray[i] = 0; // Initializing all elements to 0
        }
    }

    void insert(int value, int index) {
        if (index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        treeArray[index] = value;
    }

    int getLeftChild(int index) {
        int leftChildIndex = 2 * index;
        if (leftChildIndex >= size) {
            cout << "Left child does not exist!" << endl;
            return -1;
        }
        return treeArray[leftChildIndex];
    }

    int getRightChild(int index) {
        int rightChildIndex = 2 * index + 1;
        if (rightChildIndex >= size) {
            cout << "Right child does not exist!" << endl;
            return -1;
        }
        return treeArray[rightChildIndex];
    }

    int getParent(int index) {
        int parentIndex = index / 2;
        if (parentIndex <= 0) {
            cout << "Parent does not exist!" << endl;
            return -1;
        }
        return treeArray[parentIndex];
    }
};


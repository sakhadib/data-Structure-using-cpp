#include <iostream>
#include <queue>

using namespace std;

class AVL_tree {
private:
    class Node {
    public:
        int data;
        Node* left;
        Node* right;
        int height;

        Node(int value) {
            data = value;
            left = NULL;
            right = NULL;
            height = 1;
        }
    };

    Node* root;

    int getHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(Node* node) {
        if (node == NULL) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rotateLeft(Node* node) {
        Node* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* rotateRight(Node* node) {
        Node* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;

        return newRoot;
    }

    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        } else {
            return node; // Duplicate values are not allowed
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) {
            if (value < node->left->data) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balanceFactor < -1) {
            if (value > node->right->data) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node* findMinValueNode(Node* node) {
        Node* current = node;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == NULL || node->right == NULL) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == NULL) {
                    temp = node;
                    node = NULL;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = findMinValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == NULL) {
            return node;
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    Node* searchNode(Node* node, int value) {
        if (node == NULL || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return searchNode(node->left, value);
        } else {
            return searchNode(node->right, value);
        }
    }

    void preOrderTraversal(Node* node) {
        if (node != NULL) {
            cout << node->data << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    void inOrderTraversal(Node* node) {
        if (node != NULL) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

    void postOrderTraversal(Node* node) {
        if (node != NULL) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    void levelOrderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != NULL) {
                q.push(current->left);
            }

            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }

public:
    AVL_tree() {
        root = NULL;
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    bool search(int value) {
        Node* result = searchNode(root, value);
        return result != NULL;
    }

    int height() {
        return getHeight(root);
    }

    void preOrder() {
        preOrderTraversal(root);
    }

    void inOrder() {
        inOrderTraversal(root);
    }

    void postOrder() {
        postOrderTraversal(root);
    }

    void levelOrder() {
        levelOrderTraversal(root);
    }
};

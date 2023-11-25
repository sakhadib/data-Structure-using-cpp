#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};


class binaryTree{
    public:
        Node *root;
        binaryTree(int data){
            root = new Node(data);
        }

        void insert(int value, int parent, bool isLeft){
            Node *newNode = new Node(value);
            if(root == NULL){
                root = newNode;
                return;
            }
            Node *temp = root;
            queue<Node*> q;
            q.push(temp);
            while(!q.empty()){
                temp = q.front();
                q.pop();
                if(temp->data == parent){
                    if(isLeft){
                        temp->left = newNode;
                    }
                    else{
                        temp->right = newNode;
                    }
                    return;
                }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
            
        }

        void remove(int value){
            Node *temp = root;
            queue<Node*> q;
            q.push(temp);
            while(!q.empty()){
                temp = q.front();
                q.pop();
                if(temp->data == value){
                    temp->data = INT_MAX;
                    return;
                }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }

        void print(){
            Node *temp = root;
            queue<Node*> q;
            q.push(temp);
            while(!q.empty()){
                temp = q.front();
                q.pop();
                if(temp->data != INT_MAX){
                    cout << temp->data << " ";
                }
                if(temp->left != NULL){
                    q.push(temp->left);
                }
                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
        }

        
};
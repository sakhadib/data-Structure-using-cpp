// Tree Travarsal Operations

#include <bits/stdc++.h>
#include "TreeLL.h"
using namespace std;

void preOrder(Node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}   

void inOrder(Node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

void dfs(Node *root){
    if(root == NULL){
        return;
    }
    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node *temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right != NULL){
            s.push(temp->right);
        }
        if(temp->left != NULL){
            s.push(temp->left);
        }
    }
}

// bfs and levelOrder are same

void bfs(Node *root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}


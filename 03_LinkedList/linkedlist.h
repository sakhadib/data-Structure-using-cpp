#include <iostream>

class Node{
    public:
        int data;
        Node* next;
};

class LinkedList{
    public:
        Node *head;
        LinkedList(Node head){
            this->head = &head;
        }

        void insertEnd(int data){
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            Node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void insertStart(int data){
            Node *newNode = new Node();
            newNode->data = data;
            newNode->next = head;
            head = newNode;
        }

        void insertAt(int data, int pos){
            Node *newNode = new Node();
            newNode->data = data;
            Node *temp = head;
            for(int i = 0; i < pos - 1; i++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void deleteEnd(){
            Node *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            temp->next = NULL;
        }

        void deleteStart(){
            head = head->next;
        }

        void deleteAt(int pos){
            Node *temp = head;
            for(int i = 0; i < pos - 1; i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }

        void deleteElement(int data){
            Node *temp = head;
            while(temp->next->data != data){
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }

        void print(){
            Node *temp = head;
            while(temp != NULL){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }


};

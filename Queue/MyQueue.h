#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
    T value;
    Node * next;
    Node (T value){
        this->value = value;
        this->next = NULL;
    }
};
template<typename Q>
class MyQueue{
    Node<Q> * head;
    Node<Q> * rear;
public:
    MyQueue(){
        head = NULL;
        rear = NULL;
    };

    void push(Q value){
        Node<Q> *newNode = new Node<Q>(value);
        if(head == NULL){
            head = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void pop(){
        if(head == rear){
            head = NULL;
            rear = NULL;
            return;
        }
        Node<Q> * delNode = head;
        head = head->next;
        if(head == NULL){
            rear = NULL;
        }
        delete delNode;
    }

    bool isEmpty(){
       return  rear == NULL ? true : false;
    }

    Q Front(){
        Q check;
        if(head == NULL){
            cout<<"The Queue is underflowed "<<endl;
            return check;
        }
        return head->value;
    }
    Q Back(){
        Q check;
        if(rear == NULL){
            cout<<"The Queue is underflowed "<<endl;
            return check;
        }
        check = rear->value;
        return rear->value;
    }

};


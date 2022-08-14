#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int value;
    Node * next;
    Node * prev;
    Node(int value){
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Stack{
    Node * head;
    Node * top;
    int counter;
    int check;
public:
    Stack(){
        head = NULL;
        top = NULL;
        counter = 0;
    };
    void push(int value){
        Node * newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            top = newNode;
            counter++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        counter++;
    };
    int pop(){
        Node * delNode;
        delNode = top;
        if(top==NULL)return counter;
        if(top == head){
            top = NULL;
            head = NULL;
            counter--;
        }
        else{
            top = delNode->prev;
            top->next = NULL;
            counter--;
        }
        check = delNode->value;
        delete delNode;
        return check;
    }

    int length(){
        return counter;
    };

    bool isEmpty(){
        if(counter==0)return true;
        else return false;
    }

    int Top(){
        int chk = 0;
        if(!counter){
            cout<<"Stack is underflow"<<endl;
            return chk;
        }
        chk = top->value;
        return chk;
    }

};


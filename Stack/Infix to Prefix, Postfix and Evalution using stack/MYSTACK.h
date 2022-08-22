#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
public:
    T value;
    Node * next;
    Node * prev;
    Node(T value){
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};
template<typename T>
class MyStack{
    Node<T> * head;
    Node<T> * top;
    int counter;
public:
    MyStack(){
        this->head = NULL;
        this->top = NULL;
        this->counter = 0;
    };
    void push(T value){
        Node<T> *newNode = new Node<T>(value);
        if(head == NULL ){
            head = top = newNode;
            counter++;
            return;
        }
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
        counter++;
    };
    void pop(){
        Node<T> * delNode;
        delNode = top;
        if(top==NULL)return;
        if(top == head){
            top = head = NULL;
            counter--;
        }else{
            top = delNode->prev;
            top->next = NULL;
            counter--;
        }
        delete delNode;
    };
    int length(){
        return counter;
    };
    bool isEmpty(){
        return counter==0 ? true : false;
    };

    T mid(){
        int n = length()/2 + 1;
        Node<T> *tmp = head;
        for(int i=1;i<n;i++){
            if(tmp->next !=NULL)
                tmp= tmp->next;
        }
        return tmp->value;
    }

    T Top(){
        if(counter==0){
            cout<<"Stack is underflowed "<<endl;
            return 0;
        }
        return top->value;
    };
    void display(){
        while(!isEmpty()){
            cout<<Top()<<" ";
            pop();
        }
        cout<<endl;
    };

};

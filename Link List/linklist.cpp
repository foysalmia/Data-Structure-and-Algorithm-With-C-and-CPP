#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void printList(Node *n){
    Node *tmp = n;
    while(tmp != NULL ){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}
void deleteList( Node * &a,int n){

    if(n==0){
        Node* tmp = a;
        a = a->next;
        delete tmp;
        return;
    };

    n--;
    Node *tmp = a;
    for(int i=0;i<n-1;i++){
        tmp = tmp->next;

    }
    Node *save = tmp->next;
    tmp->next = tmp->next->next ;
    delete save;
}

void addtoList(Node* &a,int n,int val){
    if(n==0){
        Node *tmp = a;
        Node* newNode = new Node(val);
        newNode->next = tmp;
        a = newNode;
        return;
    }
    Node *tmp = a;
    n--;
    for(int i=0;i<n-1;i++){
        tmp=tmp->next;
    }
    Node* newNode = new Node(val);
    Node* previous = tmp->next;
    tmp->next = newNode;
    newNode->next = previous;
}

int main(){
    Node *head = new Node(5);
    Node *first = new Node(20);
    Node *second = new Node(6);
    Node *third = new Node(10);
    Node *fourth = new Node(9);

    //asign addresses
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    printList(head);
    deleteList(head,0);
    printList(head);
    addtoList(head,0,8);
    printList(head);

    return 0;
}

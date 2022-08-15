#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node * next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertionAtHead(Node * &head,int val){
    Node * newNode = new Node(val);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    };
    Node *tmp = head;
    while(tmp->next != head){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->next = head;
    head = newNode;
};

void insertionAtTail(Node * &head,int val){
    Node * newNode = new Node(val);
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node * tmp = head;
    while(tmp->next != head){
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->next = head;
};

void deleteAtHead(Node * &head){
    Node * tmp = head;
    if(tmp==NULL){
        cout<<"There are no value exist in the list"<<endl;
        return;
    }
    while(tmp->next != head){
        tmp= tmp->next;
    }
    tmp->next = head->next;
    head = head->next;
}

void deleteAtPosition(Node * &head,int pos){
    Node * tmp = head;
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    for(int i=1;i<pos-1;i++){
        tmp = tmp->next;
    }
    Node * delNode = tmp->next;
    tmp->next = delNode->next;
    delete delNode;
}

void insertionAtPosition(Node * &head,int pos,int val){
    if(pos==1){
        insertionAtHead(head,val);
        return;
    }
    Node * newNode = new Node(val);
    Node * tmp = head;
    for(int i=1;i<pos-1;i++){
        tmp = tmp->next;
    }
    Node * rest = tmp->next;
    tmp->next = newNode;
    newNode->next = rest;
}

void print(Node * &head){
    Node * tmp = head;
    do{
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }while(tmp != head);
    cout<<endl;
}

void instruction(){
    cout<<"Case 1 : Insert at Head"<<endl;
    cout<<"Case 2 : Insert at Tail"<<endl;
    cout<<"Case 3 : Insert at any Position"<<endl;
    cout<<"Case 4 : Delete at Position"<<endl;
    cout<<"Case 5 : Delete at Head"<<endl;
    cout<<"Case 6 : Exit"<<endl;
}

int main(){
    Node * head = NULL;
    instruction();
    int a,value,pos;
    cout<<"Your choice : ";
    cin>>a;
    while(a>=1 && a<=5){
        switch(a){
        case 1:
            cout<<"Enter value to insert at head  : ";
            cin>>value;
            insertionAtHead(head,value);
            cout<<"UPDATED LIST : ";
            print(head);
            cout<<"Next choice : ";
            cin>>a;
            break;
        case 2:
            cout<<"Enter value to insert at Tail  : ";
            cin>>value;
            insertionAtTail(head,value);
            cout<<"UPDATED LIST : ";
            print(head);
            cout<<"Next choice : ";
            cin>>a;
            break;
        case 3:
            cout<<"Enter value to insert at your desire position  : ";
            cin>>value;
            cout<<"Enter Position : ";
            cin>>pos;
            insertionAtPosition(head,pos,value);
            cout<<"UPDATED LIST : ";
            print(head);
            cout<<"Next choice : ";
            cin>>a;
            break;
        case 4:
            cout<<"Enter Position : ";
            cin>>pos;
            deleteAtPosition(head,pos);
            cout<<"UPDATED LIST : ";
            print(head);
            cout<<"Next choice : ";
            cin>>a;
            break;
        case 5:
            deleteAtHead(head);
            cout<<"UPDATED LIST : ";
            print(head);
            cout<<"Next choice : ";
            cin>>a;
            break;
        default: break;
        }
    }

    return 0;
}

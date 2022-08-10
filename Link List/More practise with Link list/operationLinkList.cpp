#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node(int value)
    {
        this->value = value;
        this->next = NULL;
    }
};

void insertAtHead(Node * &head,int value)
{
    if(head == NULL)
    {
        Node* newNode = new Node(value);
        head = newNode;
        return;
    }
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node * &head,int value)
{
    if(head == NULL)
    {
        Node* newNode = new Node(value);
        head = newNode;
        return;
    }
    Node* newNode = new Node(value);
    Node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

int countList(Node *head)
{
    int counter = 0;
    Node * tmp = head;
    while(tmp != NULL)
    {
        counter++;
        tmp = tmp->next;
    };

    return counter;
}

void insertAtSpecificPosition(Node * &head,int pos,int value){
    Node * newNode = new Node(value);
    if(pos == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    int counter = 0;
    Node* tmp = head;
    int sizelist = countList(tmp);
    while(tmp->next != NULL){
        if(counter == sizelist - 2){
            tmp->next->next = newNode;
            break;
        };
        if(pos-2 == counter){
            Node * save = tmp->next;
            tmp->next = newNode;
            newNode->next = save;
            break;
        };
        counter++;
        tmp = tmp->next;
    }
}

void print(Node* head)
{
    Node * tmp = head;
    while(tmp != NULL)
    {
        cout<<tmp->value<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

void deleteFromHead(Node * &head){
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

void chooseOption()
{
    cout<<"Choice 1: Insert at head "<<endl;
    cout<<"Choice 2: Insert at tail "<<endl;
    cout<<"Choice 3: Count the Linked List values "<<endl;
    cout<<"Choice 4: Insert at specific position "<<endl;
    cout<<"Choice 5: Display the list "<<endl;
    cout<<"Choice 6: Delete from Head"<<endl;
    cout<<"Choice 7: Delete from Tail"<<endl;
    cout<<"Choice 0: Exit"<<endl;
}

int main()
{
    Node *head = NULL;
    chooseOption();
    int option,value;
    cout<<"Choice : ";
    cin>>option;
    while(option != 0  )
    {
        switch(option)
        {
        case 1:
            cout<<"Enter value to input at head ";
            cin>>value;
            insertAtHead(head,value);
            cout<<"Next choice ";
            cin>>option;
            break;
        case 2:
            cout<<"Enter value to input at tail ";
            cin>>value;
            insertAtTail(head,value);
            cout<<"Next choice ";
            cin>>option;
            break;
        case 3:
            int elements;
            elements = countList(head);
            cout<<"Total elements are "<<elements<<endl;
            cout<<"Next choice ";
            cin>>option;
            break;
        case 4:
            cout<<"Enter position : ";
            int pos;
            cin>>pos;
            cout<<"Enter value : ";
            cin>>value;
            insertAtSpecificPosition(head,pos,value);
            cout<<"Next choice ";
            cin>>option;
            break;
        case 5:
            print(head);
            cout<<"Next choice ";
            cin>>option;
            break;
        case 6:
            cout<<"Next choice ";
            cin>>option;
            break;
        case 7:
            cout<<"Next choice ";
            cin>>option;
            break;
        default:
            break;

        }
    }

    return 0;
}

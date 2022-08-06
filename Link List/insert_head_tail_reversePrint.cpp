#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void insertAtTail(Node* &head, int val)
{
    Node* n = new Node(val);
    if(head == NULL)
    {
        head = n;
        return;
    }

    Node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = n;

}

void print(Node* head)
{
    Node* tmp = head;
    while(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;

}

void reversedListPrint(Node* head){
    if (head == NULL)return;

    reversedListPrint(head->next);
    cout<<head->val<<" ";
}


int main()
{
    Node* head = NULL;
    int n;
    cout<<"Option 1 : Insertion at Head"<<endl<<"Option 2 : Insertion at Tail"<<endl <<"Option 3 : Exit"<<endl;
    int choice = 2;
    while(choice == 2 || choice == 1)
    {
        cout<<"Enter Value : ";
        cin>>n;
        if(choice == 1)insertAtHead(head,n);
        else if(choice == 2)insertAtTail(head,n);
        cout<<"Next choice : ";
        cin>>choice;

    }

    print(head);
    cout<<"Print in reversed away :" <<endl;
    reversedListPrint(head);

    return 0;
}

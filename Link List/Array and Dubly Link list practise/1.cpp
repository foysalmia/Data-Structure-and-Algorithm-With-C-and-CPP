#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int value;
    Node * next;
    Node(int value){
        this->value = value;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head,int val)
{

    Node *newNode = new Node(val);
    if(head == NULL)
    {
        newNode->next= head;
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp != NULL)
    {
        if(tmp->next==NULL)
        {
            tmp->next = newNode;
            newNode->next = NULL;
            return;
        }
        tmp = tmp->next;
    }
}

void print(Node * &head)
{
    Node * tmp = head;
    while(tmp!=NULL)
    {
        cout<<tmp->value;
        if(tmp->next != NULL) cout<<" -> ";
        tmp = tmp->next;
    }

}

Node* replaceByValue(Node * head){
    Node * tmp = head;
    while(tmp != NULL){
        if(tmp->value % 2 == 0 && tmp->value != 0) tmp->value = -1;
        tmp = tmp->next;
    }
    return head;
}

int findMid(Node *head){
    Node * first = head;
    Node * second = head;
    if(head != NULL){
        while(first != NULL && first->next != NULL){
            first = first->next->next;
            second = second->next;
        }
    }
    return second->value;
}
int main(){
    Node * head = NULL;
    int n,a;
    cin>>n;
    while(n--){
        cin>>a;
        insertAtTail(head,a);
    }
    cout<<endl;
    print(head);
    cout<<endl<<"After replaced"<<endl;
    Node * replaced = NULL;
    replaced = replaceByValue(head);
    print(replaced);
    cout<<endl<<"Mid value: ";
    int mid;
    mid = findMid(head);
    cout<<mid<<endl;


    return 0;
}

#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

void insertAtBottom(MyStack<int> *st,int value){
    if(!st->length()){
        st->push(value);
        return;
    }
    int top = st->Top();
    st->pop();
    insertAtBottom(st,value);
    st->push(top);
}

void reverseStack(MyStack<int> *st){
    if(!st->length())return;
    int top = st->Top();
    st->pop();
    reverseStack(st);
    insertAtBottom(st,top);
}

void deleteMid(MyStack<int> *st,int mid,int pos){
    if(pos == mid){
        st->pop();
        return;
    }
    int top = st->Top();
    st->pop();
    pos++;
    deleteMid(st,mid,pos);
    st->push(top);
}

int main(){
    MyStack<int> st;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.push(a);
    }
    reverseStack(&st);
    int mid = (st.length()/2 )+ 1,pos = 1;
    deleteMid(&st,mid,pos);
    st.display();


    return 0;
}

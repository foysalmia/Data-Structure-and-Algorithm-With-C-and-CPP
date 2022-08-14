#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.pop()<<" "<<"size : "<<st.length()<<endl;
    cout<<st.Top()<<" "<<"size : "<<st.length()<<endl;
    (st.isEmpty()) ? cout<<"empty"<<endl : cout<<"Not Empty"<<endl;
    return 0;
}

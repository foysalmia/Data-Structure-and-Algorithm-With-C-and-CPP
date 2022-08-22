#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int prefixEvalution(string str){
    MyStack<int> st;
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]>='0' && str[i]<='9'){
            st.push(str[i]-'0');
        }else{
            int a = st.Top();
            st.pop();
            int b = st.Top();
            st.pop();
            switch(str[i]){
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(a-b);
                    break;
                case '*':
                    st.push(a*b);
                    break;
                case '/':
                    st.push(a/b);
                    break;
                case '^':
                    st.push(pow(a,b));
                    break;
                default:break;
            }
        }
    }
    return st.Top();
}

int main(){
    string s;
    cout<<"INPUT A PREFIX STRING : ";
    cin>>s;
    int result = prefixEvalution(s);
    cout<<result<<endl;
    return 0;
}

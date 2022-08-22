#include<bits/stdc++.h>
#include"MYSTACK.h"
using namespace std;

int precisionCalc(char c)
{
    if(c=='^')return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+' || c=='-')return 1;
    else return -1;
}

string infixToPrefix(string str)
{
    reverse(str.begin(),str.end());

    MyStack<char> st;
    string result;

    for(int i=0; i<str.length(); i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            result += str[i];
        }
        else if(str[i]==')')
        {
            st.push(str[i]);
        }
        else if(str[i]=='(')
        {
            while(!st.isEmpty() && st.Top()!=')')
            {
                result += st.Top();
                st.pop();
            }
            if(!st.isEmpty())st.pop();
        }
        else
        {
            while(!st.isEmpty() && precisionCalc(st.Top())>=precisionCalc(str[i]))
            {
                result += st.Top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(!st.isEmpty()){
        result += st.Top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    return result;

};

int prefixEvalution(string str)
{
    MyStack<int> st;
    for(int i=str.length()-1; i>=0; i--)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            st.push(str[i]-'0');
        }
        else
        {
            int a = st.Top();
            st.pop();
            int b = st.Top();
            st.pop();
            switch(str[i])
            {
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
            default:
                break;
            }
        }
    }
    return st.Top();
}

int main()
{
    string s;
    cout<<"INPUT A INFIX STRING : ";
    cin>>s;
    string result;
    result = infixToPrefix(s);
    int value;
    value = prefixEvalution(result);
    cout<<value<<endl;
    return 0;
}


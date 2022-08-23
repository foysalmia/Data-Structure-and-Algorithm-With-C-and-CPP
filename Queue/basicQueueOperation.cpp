#include<bits/stdc++.h>
#include"MyQueue.h"
using namespace std;

typedef pair<int,char>Queue;

int main(){
    MyQueue<Queue> qu;

    qu.push(make_pair(1 ,'a'));
    qu.push(make_pair(10 ,'b'));
    qu.push(make_pair(11 ,'c'));
    qu.push(make_pair(15 ,'d'));

    Queue print;
    print = qu.Front();

    while(!qu.isEmpty()){
        Queue del;
        del = qu.Front();
        cout<<del.first<<" "<<del.second<<endl;
        qu.pop();

    }
    return 0;
}

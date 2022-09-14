#include<bits/stdc++.h>
using namespace std;
class Priority_Queue{
private:
    vector<int> v;
    int leftChild(int i){
        return (i*2)+1;
    }
    int rightChild(int i){
        return (i*2)+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void heapify(int start){
        int left_index = leftChild(start);
        int right_index = rightChild(start);
        int smallest = start;

        if(left_index < v.size() && v[left_index] < v[smallest]){
            smallest = left_index;
        }
        if(right_index < v.size() && v[right_index]<v[smallest]){
            smallest = right_index;
        }

        swap(v[start],v[smallest]);
        if(smallest != start){
            heapify(smallest);
        }

    }
public:
    void push(int val){
        v.push_back(val);
        int insert_index = v.size()-1;
        while(v[insert_index] < v[parent(insert_index)]){
            if(insert_index==0)break;
            swap(v[insert_index] , v[parent(insert_index)]);
            insert_index = parent(insert_index);
        }
    }
    int top(){
        return v[0];
    }
    void pop(){
        v[0]=v[v.size()-1];
        v.pop_back();
        heapify(0);
    }
    bool isEmpty(){
        return v.size()==0;
    }

};

int main(){
    Priority_Queue pq;
    pq.push(5);
    pq.push(15);
    pq.push(50);
    pq.push(25);
    pq.push(55);

    while(!pq.isEmpty()){
        int v=pq.top();
        pq.pop();
        cout<<v<<" ";
    }
    cout<<endl;

    return 0;
}


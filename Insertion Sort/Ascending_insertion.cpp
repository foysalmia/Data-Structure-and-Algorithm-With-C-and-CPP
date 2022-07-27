#include<bits/stdc++.h>

using namespace std;

void print_array(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;

    int a[n];
    cout<<"Enter elements to the array : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Before Sorting : ";
    print_array(a,n);

    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(a[j]>key && j>= 0){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

    cout<<"After Insertion Sorting by ascending order : ";
    print_array(a,n);
    return 0;
}


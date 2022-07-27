
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
        int flag = 0;
        for(int j=0;j<n-i;j++){
            if(a[j]<a[j+1]){
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }

    cout<<"After Bubble Sorting by Decending order : ";
    print_array(a,n);
    return 0;
}

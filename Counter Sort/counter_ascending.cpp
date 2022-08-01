#include<bits/stdc++.h>

using namespace std;

void print(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int max_value(int *a,int n){
    int maxi = a[0];
    for(int i=0;i<n;i++)
        maxi = max(maxi,a[i]);
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int maxi = max_value(arr,n);

    int counter[maxi+1] = {0};
    for(int i=0;i<n;i++){
        counter[arr[i]]++;
    }

    for(int i=1;i<=maxi;i++){
        counter[i] += counter[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--counter[arr[i]]] = arr[i];
    }
    print(output,n);

    return 0;
}

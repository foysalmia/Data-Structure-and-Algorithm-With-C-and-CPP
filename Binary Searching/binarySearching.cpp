#include<bits/stdc++.h>

using namespace std;

int BinarySearch(int a[],int x,int lb,int up)
{
    if(lb<=up)
    {
        int mid = (lb+up)/2;
        if(x==a[mid])
            return mid;
        else if(x<a[mid])
            return BinarySearch(a,x,lb,mid-1);
        else
            return BinarySearch(a,x,mid+1,up);
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;

    int a[n];
    cout<<"Enter the elements of the array : "<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

flag:
    int searchValue;
    cout<<"Enter the number which you want to search : ";
    cin>>searchValue;

    int index = BinarySearch(a,searchValue,0,n-1);

    if(index == -1)
        cout<<"NOT FOUND"<<endl;
    else
        cout<<"Your value is at "<<index+1<<"th position"<<endl;

    char c;
    cout<<"Do you want to search again (Y/N) : ";
    cin>>c;
    if(toupper(c) == 'Y')
        goto flag;
    else
        return 0;


    return 0;
}



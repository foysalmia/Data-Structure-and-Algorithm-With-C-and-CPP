#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the size : ";
    cin>>n;

    int a[n];
    cout<<"Enter the elements in array :"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

Flag:
    char c ;
    cout<<"Do you want to search (Y/N) : ";
    cin>>c;

    while(toupper(c) == 'Y')
    {
        int searhValue;
        cout<<"Enter value you want to search : ";
        cin>>searhValue;
        int flag=-1;
        for(int i=0; i<n; i++)
        {
            if(searhValue == a[i])
            {
                flag = 1;
                cout<<"Your value in " <<i+1<<"th position"<<endl;
            }
        };

        if(flag == -1)
        {
            cout<<"NOT FOUND"<<endl;
        };
        goto Flag;

    }
    return 0;
}



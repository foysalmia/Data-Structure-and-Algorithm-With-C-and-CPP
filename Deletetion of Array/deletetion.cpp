
#include <iostream>

using namespace std;

int
main ()
{
    int a[100];

    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    cout << "Enter elements of the array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    cout << "Given array is : ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;

    int pos;
    cout << "Select which position you want to remove : ";
    cin >> pos;

    if (pos == size)
    {
        size--;
    }
    else
    {
        for (int i = pos; i <= size - 1; i++)
        {
            a[i - 1] = a[i];
        }
        size--;
    };


    cout << "After Deletetion : ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}



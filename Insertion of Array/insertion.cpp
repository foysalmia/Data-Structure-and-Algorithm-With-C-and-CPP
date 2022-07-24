

#include <iostream>

using namespace std;

int
main ()
{
    int array[100];

    int size;
    cout << "Enter size of your array : ";
    cin >> size;

    cout << "Enter array elements : ";
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    cout << "Given Array is : ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl << endl;

    int pos, element;
flag:
    cout << "Enter the position : ";
    cin >> pos;
    if (pos <= -1 || pos > size)
    {
        cout << "Given position is not valid ;" << endl;
        goto flag;
    }
    cout << "Enter the element : ";
    cin >> element;
    for (int i = size - 1; i >= pos - 1; i--)
    {
        array[i + 1] = array[i];
    }
    array[pos - 1] = element;

    cout << "Array after insertion " << endl;
    for (int i = 0; i <= size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}


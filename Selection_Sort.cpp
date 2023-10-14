#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the array size: ";
    cin >> n;
    int array[n];

    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int min_indx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min_indx])
            {
                min_indx = j;
            }
        }
        swap(array[i], array[min_indx]);
    }

    cout << "Your Selection  sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}
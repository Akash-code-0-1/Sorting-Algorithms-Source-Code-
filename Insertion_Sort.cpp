#include <iostream>
using namespace std;

int main()
{

    int n, j;
    cout << "Enter the array size: ";
    cin >> n;
    int array[n];

    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    for (int i = 1; i < n; i++)
    {
        int temp = array[i];
        j = i - 1;
        while (j >= 0 && temp < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }

    cout << "Your Insertion sorted Array is: " << endl;
    for (int j = 0; j < n; j++)
    {
        cout << array[j] << endl;
    }
}
#include <iostream>
using namespace std;

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
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

    for (int i = 0; i < n; i++)
    {
        bool swaped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j + 1] < array[j])
            {
                swap(array, j + 1, j);
            }
        }
        if (swaped)
        {
            break;
        }
    }

    cout << "Your Bubble sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}
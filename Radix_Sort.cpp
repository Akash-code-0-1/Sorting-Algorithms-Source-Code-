#include <iostream>
using namespace std;

int getMaxDigit(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    int digitCount = 0;
    while (max > 0)
    {
        max /= 10;
        digitCount++;
    }
    return digitCount;
}

void radixSort(int array[], int size)
{
    int maxDigits = getMaxDigit(array, size);
    int exp = 1;

    for (int i = 0; i < maxDigits; i++)
    {
        int output[size];
        int count[10] = {0};

        for (int j = 0; j < size; j++)
        {
            int digit = (array[j] / exp) % 10;
            count[digit]++;
        }

        for (int j = 1; j < 10; j++)
        {
            count[j] += count[j - 1];
        }

        for (int j = size - 1; j >= 0; j--)
        {
            int digit = (array[j] / exp) % 10;
            output[count[digit] - 1] = array[j];
            count[digit]--;
        }

        for (int j = 0; j < size; j++)
        {
            array[j] = output[j];
        }

        exp *= 10;
    }
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

    radixSort(array, n);

    cout << "Your Radix sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}

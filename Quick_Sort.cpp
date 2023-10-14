#include <iostream>
using namespace std;

int partition(int array[], int lb, int up);
void quickSort(int array[], int lb, int up);

void quickSort(int array[], int lb, int up)
{

    if (lb < up)
    {
        int loc = partition(array, lb, up);
        quickSort(array, lb, loc - 1);
        quickSort(array, loc + 1, up);
    }
}
int partition(int array[], int lb, int up)
{
    int pivot = array[lb];
    int start = lb + 1;
    int end = up;

    while (start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
        }
    }
    int temp = array[lb];
    array[lb] = array[end];
    array[end] = temp;

    return end;
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
    int lb = 0;

    quickSort(array, lb, n - 1);
    cout << "Your Quick sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}
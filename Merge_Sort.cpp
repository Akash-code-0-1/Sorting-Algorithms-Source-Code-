#include <iostream>
using namespace std;
void mergeSort(int array[], int lb, int up);
void merge(int array[], int lb, int mid, int up);

void mergeSort(int array[], int lb, int up)
{
    if (lb < up)
    {

        int mid = ((lb + up) / 2);
        mergeSort(array, lb, mid);
        mergeSort(array, mid + 1, up);
        merge(array, lb, mid, up);
    }
}

void merge(int array[], int lb, int mid, int up)
{
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int array2[up - lb + 1];

    while (i <= mid && j <= up)
    {
        if (array[i] < array[j])
        {
            array2[k - lb] = array[i];
            i++;
        }
        else
        {
            array2[k - lb] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        array2[k - lb] = array[i];
        i++;
        k++;
    }

    while (j <= up)
    {
        array2[k - lb] = array[j];
        j++;
        k++;
    }

    for (k = lb; k <= up; k++)
    {
        array[k] = array2[k - lb];
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
    int lb = 0;

    mergeSort(array, lb, n - 1);
    cout << "Your Merge sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
}




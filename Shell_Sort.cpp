#include <iostream>
#include <vector>

using namespace std;

void shellSort(vector<int> &array)
{
    int n = array.size();
    int gap = n / 2;

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = array[i];
            int j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        gap /= 2;
    }
}

int main()
{
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    vector<int> array(n);

    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    shellSort(array);

    cout << "Your Shell sorted Array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}

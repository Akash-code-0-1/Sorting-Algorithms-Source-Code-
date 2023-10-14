#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int> &array)
{
    int maxValue = *max_element(array.begin(), array.end());
    int minValue = *min_element(array.begin(), array.end());

    int range = maxValue - minValue + 1;
    vector<int> countArray(range, 0);

    for (int i = 0; i < array.size(); i++)
    {
        countArray[array[i] - minValue]++;
    }

    int outputIndex = 0;
    for (int i = 0; i < range; i++)
    {
        while (countArray[i] > 0)
        {
            array[outputIndex] = i + minValue;
            outputIndex++;
            countArray[i]--;
        }
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

    countingSort(array);

    cout << "Your Counting sorted Array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}

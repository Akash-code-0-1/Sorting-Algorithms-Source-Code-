#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<int> &array)
{
    int max = *max_element(array.begin(), array.end());
    int min = *min_element(array.begin(), array.end());
    int bucketSize = 5;

    int bucketCount = (max - min) / bucketSize + 1;
    vector<vector<int>> buckets(bucketCount);

    for (int i = 0; i < array.size(); i++)
    {
        int bucketIndex = (array[i] - min) / bucketSize;
        buckets[bucketIndex].push_back(array[i]);
    }

    int outputIndex = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        sort(buckets[i].begin(), buckets[i].end());

        for (int j = 0; j < buckets[i].size(); j++)
        {
            array[outputIndex] = buckets[i][j];
            outputIndex++;
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

    bucketSort(array);

    cout << "Your Bucket sorted Array is:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}

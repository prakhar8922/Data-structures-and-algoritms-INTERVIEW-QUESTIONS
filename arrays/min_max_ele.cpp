#include <iostream>
using namespace std;
int minElement(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}
int maxElement(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {

        if (arr[i] > max)
        {

            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[] = {12, 1234, 45, 67, 1};
    int size = sizeof(arr) / sizeof(int);
    int result1 = minElement(arr, size);
    int result2 = maxElement(arr, size);

    cout << "maximum element of array: " << result2 << endl;

    cout << "minimum element of array: " << result1 << endl;

    return 0;
}
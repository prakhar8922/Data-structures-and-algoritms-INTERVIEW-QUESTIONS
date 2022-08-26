#include <iostream>
using namespace std;
void sortArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = i+ 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {0, 23, 14, 12, 9};
    int k = sizeof(arr) / sizeof(int);
    cout << "before sorting" << endl;

    for (int i = 0; i < k; i++)
    {

        cout << " " << arr[i];
    }
    cout << endl;

    sortArr(arr, k);
    cout << "after sorting" << endl;

    for (int i = 0; i < k; i++)
    {

        cout << " " << arr[i];
    }
    return 0;
}
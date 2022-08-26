#include <iostream>
using namespace std;
void negSort(int arr[], int n)
{
    int temp, j = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] < 0)
        {
            if (i != j)
            {

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                
            }
            j++;
        }
    }
}
int main()
{

    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int n = sizeof(arr) / sizeof(int);
    negSort(arr, n);
    for (int i = 0; i < n; i++)
    {

        cout << " " << arr[i];
    }
    return 0;
}
#include <iostream>
using namespace std;
void reverseArr(int arr[], int n)
{

    for (int i = 0; i < n/2; i++)
    {
        int temp = arr[i];

        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << " "<<arr[i];
    }
}
int main()

{
    int arr[] = {4, 5, 1, 2};
    int k = sizeof(arr) / sizeof(int);
reverseArr(arr,k);
    return 0;
}
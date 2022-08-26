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
    int arr[] ={7, 10, 4, 3, 20, 15} ;
    int n = sizeof(arr) / sizeof(int);
     int k=4;
    sortArr(arr, n);
    cout << " sorted array" << endl;

    for (int i = 0; i < n; i++)
    {

        cout << " " << arr[i];
    }

    cout<<endl;

    cout<<arr[k-1];
    return 0;
}
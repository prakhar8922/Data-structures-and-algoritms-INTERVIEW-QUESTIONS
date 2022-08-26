#include <iostream>
using namespace std;
int frequencyNum(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == x)
        {

            count++;
        }
    }
    return count;
}
int main()
{
    int arr[] = {1, 2, 3};
    int x = 4;
    int n = sizeof(arr) / sizeof(int);
    cout<<frequencyNum(arr,n,x);
    return 0;
}
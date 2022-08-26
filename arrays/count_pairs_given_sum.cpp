#include <iostream>
using namespace std;
int Nopairs(int arr[], int n, int x)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == x)
            {

                count++;
            }
        }
    }
    return count;
}
int main()
{
    int arr[] = {1, 5, 7, -1};
    int sum = 6;
   int n = sizeof(arr) / sizeof(int);
    cout<<Nopairs(arr,n,sum);
    return 0;
}
//time complexity O(n^2) , can be done in O(n)with map concept
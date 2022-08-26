//#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void missingNum(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {

            cout << i + 1;
             break;
        }
       
    }
}

int main()
{
    int arr[] = {1, 2, 3, 5};
    int n = sizeof(arr) / sizeof(int);
    missingNum(arr,n);
    return 0;
}
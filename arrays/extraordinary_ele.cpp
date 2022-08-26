#include <bits/stdc++.h>

using namespace std;
int ExtraordinaryEle(int arr[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *max_element(arr, arr + i))
        {
            count++;
        }
        else if (arr[i] < *min_element(arr, arr + i))
        {
            count++;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;

    {

        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << ExtraordinaryEle(arr, n);
    }

    return 0;
}
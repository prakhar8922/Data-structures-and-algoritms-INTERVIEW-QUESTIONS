#include <iostream>
using namespace std;
void FirstEle(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {

                cout << arr[i];
                count++;

                break;
            }
        }
        if (count == 1)
        {

            break;
        }
    }
}
int main()
{
    int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    FirstEle(arr, n);
    return 0;
}
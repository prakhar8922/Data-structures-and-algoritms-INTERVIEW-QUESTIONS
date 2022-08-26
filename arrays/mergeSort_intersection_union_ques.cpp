#include <iostream>
using namespace std;
void mergeSortUnion(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            cout << arr1[i++] << " ";

        else if (arr2[j] < arr1[i])
            cout << arr2[j++] << " ";

        else
        {
            cout << arr2[j++] << " ";
            i++;
        }
    }

    /* Print remaining elements of the larger array */
    while (i < m)
        cout << arr1[i++] << " ";

    while (j < n)
        cout << arr2[j++] << " ";
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void mergeSorIntersection(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n)
    {
 if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else /* if arr1[i] == arr2[j] */
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
        
}
    int main()
     {  
        
        int arr1[] = {1, 3, 4, 5, 7};
        int n1 = sizeof(arr1) / sizeof(int);

        int arr2[] = {2, 3, 5, 6};
        int n2 = sizeof(arr2) / sizeof(int);

        mergeSortUnion(arr1, arr2, n1, n2);
        cout<<endl;
        mergeSorIntersection(arr1,arr2,n1,n2);
        return 0;
    }
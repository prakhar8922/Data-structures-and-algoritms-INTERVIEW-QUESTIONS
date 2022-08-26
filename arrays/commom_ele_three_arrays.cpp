#include <iostream>
using namespace std;
void mergeIntersection(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {

        // If x = y and y = z, print any of them and move ahead
        // in all arrays
        if (A[i] == B[j] && B[j] == C[k])
        {
            cout << A[i] << " ";
            i++;
            j++;
            k++;
        }

        // x < y
        else if (A[i] < B[j])
            i++;

        // y < z
        else if (B[j] < C[k])
            j++;

        // We reach here when x > y and z < y, i.e., z is smallest
        else
            k++;
    }
}
int main()
{
    int arr1[] = {1, 5, 5};
    int arr2[] = {3, 4, 5, 5, 10};
    int arr3[] = {5, 5, 10, 20};
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    int n3 = sizeof(arr3) / sizeof(int);
    mergeIntersection(arr1, arr2, arr3, n1, n2, n3);
    return 0;
}
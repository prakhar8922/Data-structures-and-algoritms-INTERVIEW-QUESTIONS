#include <bits/stdc++.h>
using namespace std;

// function for adding one to number
void incrementVector(vector<int> &arr)
{
    int n = arr.size();

    // Add 1 to last digit and find carry
    arr[n-1] += 1;
    int carry = arr[n-1]/10;
    arr[n-1] = arr[n-1] % 10;

    // Traverse from second last digit
    for (int i=n-2; i>=0; i--)
    {
        if (carry == 1)
        {
           arr[i] += 1;
           carry = arr[i]/10;
           arr[i] = arr[i] % 10;
        }
    }

    // If carry is 1, we need to add
    // a 1 at the beginning of vector
    if (carry == 1)
      arr.insert(arr.begin(), 1);
}

// driver code
int main()
{
    vector<int> vect{1, 7, 8, 9};

    incrementVector(vect);

    for (int i=0; i<vect.size(); i++)
       cout << vect[i] << " ";

    return 0;
}

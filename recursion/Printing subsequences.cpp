// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void subs(int idx, int arr[], vector<int> &ds, int n)
{
    if (idx >= n)
    {
        for (auto it : ds)
        {
            cout << it << " ";
        }
        if (ds.size() == 0)
            cout << "{}" << endl;
        return;
    }
    ds.push_back(arr[idx]); // when taking the elemenent in the subsequence
    subs(idx + 1, arr, ds, n);
    ds.pop_back(); // when not taking the element in the subsequence
    subs(idx + 1, arr, ds, n);
}

// Driver code
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    subs(0, arr, ds, n);

    return 0;
}

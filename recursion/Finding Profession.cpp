// Consider a special family of Engineers and Doctors with following rules :

// Everybody has two children.
// First child of an Engineer is an Engineer and second child is a Doctor.
// First child of an Doctor is Doctor and second child is an Engineer.
// All generations of Doctors and Engineers start with Engineer.
// We can represent the situation using below diagram:

//                 E
//            /        \
//           E          D
//         /   \       /  \
//        E     D     D    E
//       / \   / \   / \   / \
//      E   D D   E  D  E  E  D
// Given level and position(pos) of a person in above ancestor tree, find profession of the person.

// Example 1:

// Input: level = 4, pos = 2
// Output: Doctor
// Explaination: It is shown in the tree given
// in question.
// Example 2:

// Input: level = 3, pos = 4
// Output: Engineer
// Explaination: Already given in the tree in
// question.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // The idea is based on the fact that profession of a person depends on following two.
    // Profession of parent.
    // Position of node : If position of a node is odd, then its profession is same as its parent. Else profession is different from its parent.
    char profession(int level, int pos)
    {
        if (pos == 1 or level == 1)
        {
            return 'e';
        }
        char prof = profession(level - 1, (pos + 1) / 2);
        if (pos % 2 != 0 and prof == 'e')
        {
            return 'e';
        }
        if (pos % 2 == 0 and prof == 'd')
        {
            return 'e';
        }
        else
            return 'd';
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int level, pos;
        cin >> level >> pos;

        Solution ob;
        if (ob.profession(level, pos) == 'd')
            cout << "Doctor\n";
        else
            cout << "Engineer\n";
    }
    return 0;
}
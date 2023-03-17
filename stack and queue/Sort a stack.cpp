// Given a stack, the task is to sort it such that the top of the stack has the greatest element.

// Example 1:

// Input:
// Stack: 3 2 1
// Output: 3 2 1
// Example 2:

// Input:
// Stack: 11 2 32 3 41
// Output: 41 32 11 3 2
// Your Task:
// You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

// Expected Time Complexity: O(N*N)
// Expected Auxilliary Space: O(N) recursive.

// Constraints:
// 1<=N<=100

#include <bits/stdc++.h>
void insertAtPlace(stack<int> &s, int val)
{
    if (s.empty() or s.top() <= val)
    {
        s.push(val);
        return;
    }
    int top = s.top();
    s.pop();
    insertAtPlace(s, val);
    s.push(top);
}
void sortStack(stack<int> &s)
{
    // Write your code here
    if (s.empty())
        return;
    int top = s.top();
    s.pop();
    sortStack(s);
    insertAtPlace(s, top);
}

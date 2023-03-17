#include <bits/stdc++.h>
// Stack class.
class Stack
{

public:
    int *arr, size, topele;
    Stack(int capacity)
    {
        // Write your code here.
        topele = -1;
        size = capacity;
        arr = new int[capacity];
    }

    void push(int num)
    {
        // Write your code here.
        if (topele == size - 1)
        {
        }
        else
        {
            arr[++topele] = num;
        }
    }

    int pop()
    {
        // Write your code here.
        if (topele != -1)
        {
            return arr[topele--];
        }
    }

    int top()
    {
        // Write your code here.
        return topele == -1 ? -1 : arr[topele];
    }

    int isEmpty()
    {
        // Write your code here.
        return topele == -1 ? 1 : 0;
    }

    int isFull()
    {
        // Write your code here.
        return topele == size - 1 ? 1 : 0;
    }
};
// Implement Queue Data Structure using Array with all functions like pop, push, top, size, etc.

#include <bits/stdc++.h>
class Queue
{
    int qfront, rear;
    int *arr;

public:
    Queue()
    {
        // Implement the Constructor
        qfront = rear = 0;
        arr = new int[100000];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (rear == 0 or rear == qfront)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        arr[rear++] = data;
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (qfront == rear)
            return -1;
        int element = arr[qfront];
        qfront++;
        return element;
    }

    int front()
    {
        // Implement the front() function
        if (rear == 0 or qfront == rear)
            return -1;
        return arr[qfront];
    }
};
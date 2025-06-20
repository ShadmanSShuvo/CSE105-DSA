#include <bits/stdc++.h>
using namespace std;

/* Function to reverse the first
   K elements of the Queue */
void reverseFirstK(queue<int>& q, int k)
{
    if (q.empty() == true || k > q.size())
        return;
    if (k <= 0)
        return;

    stack<int> s;

    /* Push the first K elements
       into a Stack*/
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    /* Enqueue the contents of stack
       at the back of the queue*/
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    /* Remove the remaining elements and
       enqueue them at the end of the Queue*/
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }
}

/* Utility Function to print the Queue */
void Print(queue<int>& q)
{
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    

    int k = 3;
    reverseFirstK(q, k);
    Print(q);
}
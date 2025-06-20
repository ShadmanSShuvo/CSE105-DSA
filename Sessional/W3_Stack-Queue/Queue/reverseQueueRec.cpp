// C++ code for reversing a queue
#include <bits/stdc++.h>
using namespace std;

// Utility function to print the queue
void printQueue(queue<int> q)
{
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

// Recursive function to reverse the queue
void reverseQueue(queue<int>& q)
{
    // Base case
    if (q.empty())
        return;

    // Dequeue current item (from front)  
    long long int data = q.front();
    q.pop();

    // Reverse remaining queue  
    reverseQueue(q);

    // Enqueue current item (to rear)  
    q.push(data);
}

// Driver code
int main()
{
    queue<int> q;
    q.push(56);
    q.push(27);
    q.push(30);
    q.push(45);
    q.push(85);
    q.push(92);
    q.push(58);
    q.push(80);
    q.push(90);
    q.push(100);
    reverseQueue(q);
    printQueue(q);
}
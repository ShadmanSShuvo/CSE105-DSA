#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void print(queue<int>& q)
{
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}

// Function to reverse the queue
void reverseQueue(queue<int>& q)
{
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    reverseQueue(q);
    print(q);
}
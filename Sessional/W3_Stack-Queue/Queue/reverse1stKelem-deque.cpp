#include <bits/stdc++.h>
using namespace std;
// Function to reverse first k element of the queue
void reverseFirstK(queue<int>& q, int k)
{
    deque<int> d;

    // Dequeue the first k elements of the queue and push
    // them onto a deque
    for (int i = 0; i < k; i++) {
        d.push_front(q.front());
        q.pop();
    }

    // Pop the elements from the deque and enqueue them back
    // into the queue
    while (!d.empty()) {
        q.push(d.front());
        d.pop_front();
    }

    // Dequeue the remaining elements from the queue and
    // enqueue them back into the queue
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
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

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
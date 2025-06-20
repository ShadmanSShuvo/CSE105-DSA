#include <bits/stdc++.h>
using namespace std;

void moveKToEnd(queue<int>& q, int k) {
    if (k == 0) return;
    int e = q.front();
    q.pop();
    moveKToEnd(q, k - 1);
    q.push(e);
}

// Main function to reverse first k elements of a queue
queue<int> reverseFirstK(queue<int> q, int k) {
    moveKToEnd(q, k);
    int s = q.size() - k;
    while (s-- > 0) {
        int x = q.front();
        q.pop();
        q.push(x);
    }
    return q;
}

int main() {
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    int k = 3;
    queue = reverseFirstK(queue, k);

    // Printing queue
    while (!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }
    return 0;
}
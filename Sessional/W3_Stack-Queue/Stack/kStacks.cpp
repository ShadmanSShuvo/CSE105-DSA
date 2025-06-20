#include <bits/stdc++.h>
using namespace std;

class kStacks {
private:
    vector<int> arr;
    int n, k;
    vector<int> top;
    vector<int> next;
    int freeIndex;
    
public:
    kStacks(int n, int k) {
        this->n = n;
        this->k = k;
        arr.resize(n);
        top.resize(k, -1);
        next.resize(n);
        
        // Initialize all spaces as free
        freeIndex = 0;
        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }
    
    // Function to push element x into m'th stack
    bool push(int x, int m) {
        
        // Check if there is space available in the stack
        if (freeIndex == -1) {
            return false;  
        }
        
        // Get the index of the free space
        int i = freeIndex;
        
        // Update freeIndex to the next free slot
        freeIndex = next[i];
        
        // Insert the element into the correct stack
        next[i] = top[m];
        top[m] = i;
        arr[i] = x;
        
        return true;
    }
    
    // Function to pop top element from m'th stack
    int pop(int m) {
        if (top[m] == -1) {
            return -1; 
        }
        
        // Get the top element from stack m
        int i = top[m];
        
        // Update the top of stack m
        top[m] = next[i];
        
        // Return the popped element and update the freeIndex
        next[i] = freeIndex;
        freeIndex = i;
        
        return arr[i];
    }
};

int main() {
    int n = 5, k = 4;
    kStacks* s = new kStacks(n, k);
    
    
    vector<vector<int>> queries = {
        {1, 15, 0},  
        {1, 25, 1},  
        {1, 35, 2},  
        {1, 45, 3},  
        {1, 55, 0},
        {2, 0},     
        {2, 1},     
        {1, 55, 0},  
        {2, 3}      
    };
    
    for (auto q : queries) {
        if (q[0] == 1) {
            if (s->push(q[1], q[2])) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        } else {
            cout << s->pop(q[1]) << " ";
        }
    }

    return 0;
}
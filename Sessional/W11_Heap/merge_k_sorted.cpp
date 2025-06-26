#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to store element, array index, and element index
struct Node {
    int value, arrayIdx, elementIdx;
    Node(int v, int ai, int ei) : value(v), arrayIdx(ai), elementIdx(ei) {}
    bool operator>(const Node& other) const { return value > other.value; }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    vector<int> result;
    priority_queue<Node, vector<Node>, greater<Node>> minHeap;
    
    // Initialize heap with first element of each array
    for (int i = 0; i < arrays.size(); i++) {
        if (!arrays[i].empty()) {
            minHeap.push(Node(arrays[i][0], i, 0));
        }
    }
    
    // Extract min and push next element
    while (!minHeap.empty()) {
        Node node = minHeap.top();
        minHeap.pop();
        result.push_back(node.value);
        
        // If there are more elements in the same array, push the next one
        if (node.elementIdx + 1 < arrays[node.arrayIdx].size()) {
            minHeap.push(Node(arrays[node.arrayIdx][node.elementIdx + 1], node.arrayIdx, node.elementIdx + 1));
        }
    }
    
    return result;
}

int main() {
    vector<vector<int>> arrays = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    vector<int> merged = mergeKSortedArrays(arrays);
    cout << "Merged array: ";
    for (int val : merged) {
        cout << val << " ";
    }
    cout << endl; // Output: 1 2 3 4 5 6 7 8 9
    return 0;
}
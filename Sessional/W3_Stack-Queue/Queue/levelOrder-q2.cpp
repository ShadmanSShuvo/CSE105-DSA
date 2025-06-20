// C++ Program to print level Order traversal of Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to do level order traversal and return a 2D vector
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
    if (root == nullptr)
        return result;

    // Create an empty queue for level order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
      
        // nodeCount (queue size) indicates number of 
      	// nodes at current level.
        int nodeCount = q.size();
        vector<int> currentLevel;

        for(int i = 0; i < nodeCount; i++) {
            Node* node = q.front();
            q.pop();
            currentLevel.push_back(node->data);

            if (node->left != nullptr)
                q.push(node->left);
            if (node->right != nullptr)
                q.push(node->right);
        }
        result.push_back(currentLevel);
    }

    return result;
}

int main() {
  
    // Binary tree structure:
    //
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
  
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> traversal = levelOrder(root);
    for (const auto& level : traversal) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}

// O(n) time | O(n) space - where n is the number of nodes in the tree
// (queue size) and the space is used to store the result (vector of vectors
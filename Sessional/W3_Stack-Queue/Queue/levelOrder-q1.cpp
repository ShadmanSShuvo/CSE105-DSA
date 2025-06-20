// C++ Program to print level Order 
// traversal of Binary Tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to do level order traversal and 
// return a 2D vector
vector<vector<int>> levelOrder(Node *root) {
  
    vector<vector<int>> result;
    if (root == nullptr) return result;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);

    vector<int> currentLevel;

    while (q.size() > 1) {
        Node *curr = q.front();
        q.pop();

        // Condition to check occurrence of next level.
        if (curr == nullptr) {
            result.push_back(currentLevel); 
            currentLevel.clear();           
            q.push(nullptr);                   
        } 
        else {
            currentLevel.push_back(curr->data);  

            if (curr->left) q.push(curr->left);  
            if (curr->right) q.push(curr->right); 
        }
    }

    if (!currentLevel.empty()) {
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
    //     / \   \
    //    4   5   6


    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    vector<vector<int>> traversal = levelOrder(root);
    for (const auto &level : traversal) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}

// O(n) time | O(n) space
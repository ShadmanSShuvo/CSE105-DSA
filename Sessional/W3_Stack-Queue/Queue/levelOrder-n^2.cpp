// C++ Program to print level Order
// traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    Node(int key) {
        data = key;
        left = nullptr;  
        right = nullptr; 
    }
};

// Print nodes at a given level
void printGivenLevel(Node *root, int level, vector<int> &levelNodes) {
    if (root == nullptr)
        return;
    if (level == 1) {
        levelNodes.push_back(root->data);
    }
    else if (level > 1) {
        printGivenLevel(root->left, level - 1, levelNodes);
        printGivenLevel(root->right, level - 1, levelNodes);
    }
}

// Compute the "height" of a tree -- the number of
// nodes along the longest path from the root node
// down to the farthest leaf node.
int height(Node *node) {
    if (node == nullptr)
        return 0;

    // Compute the height of each subtree
    int lheight = height(node->left);
    int rheight = height(node->right);

    // Use the larger one without the ternary operator
    if (lheight > rheight) {
        return lheight + 1;
    }
    else {
        return rheight + 1;
    }
}

// Function to return level order traversal as 
// a vector of vectors
vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> result;
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        vector<int> levelNodes;
        printGivenLevel(root, i, levelNodes);
        result.push_back(levelNodes);
    }
    return result;
}


int main() {

    // Binary Tree Representation
    //
    //       1
    //     /   \
    //    2     3
    //   / \
    //  4   5

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> result = levelOrder(root);
    for (const auto &level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
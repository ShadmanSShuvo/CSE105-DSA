#include <iostream>
using namespace std;

struct BTNode {
    char data;
    BTNode *left, *right;
    BTNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    BTNode* root;

    // Count internal nodes (nodes with at least one child)
    int countInternalNodes(BTNode* node) {
        if (!node || (!node->left && !node->right)) return 0;
        return 1 + countInternalNodes(node->left) + countInternalNodes(node->right);
    }

    // Count leaf nodes (nodes with no children)
    int countLeafNodes(BTNode* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        return countLeafNodes(node->left) + countLeafNodes(node->right);
    }

    // Delete tree
    void deleteTree(BTNode* node) {
        if (node) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Create a sample full binary tree
    void createFullBinaryTree() {
        root = new BTNode('A');
        root->left = new BTNode('B');
        root->right = new BTNode('C');
        root->left->left = new BTNode('D');
        root->left->right = new BTNode('E');
        root->right->left = new BTNode('F');
        root->right->right = new BTNode('G');
        // Structure:      A
        //               /   \
        //              B     C
        //             / \   / \
        //            D   E F   G
    }

    // Verify Full Binary Tree Theorem
    void verifyTheorem() {
        int internal = countInternalNodes(root);
        int leaves = countLeafNodes(root);
        cout << "Internal Nodes: " << internal << endl;
        cout << "Leaf Nodes: " << leaves << endl;
        cout << "Theorem (Leaves = Internal + 1): " 
             << (leaves == internal + 1 ? "Verified" : "Not Verified") << endl;
    }

    ~BinaryTree() {
        deleteTree(root);
    }
};

int main() {
    BinaryTree tree;
    tree.createFullBinaryTree();
    tree.verifyTheorem();
    return 0;
}
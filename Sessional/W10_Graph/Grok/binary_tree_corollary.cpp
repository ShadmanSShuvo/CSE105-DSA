#include <iostream>
using namespace std;

struct BTNode {
    char data;
    BTNode *left, *right;
    BTNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    BTNode* root;

    // Count total nodes
    int countNodes(BTNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Count empty subtrees (null pointers)
    int countEmptySubtrees(BTNode* node) {
        if (!node) return 1; // Null pointer is an empty subtree
        return countEmptySubtrees(node->left) + countEmptySubtrees(node->right);
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

    // Create a sample binary tree
    void createSampleTree() {
        root = new BTNode('A');
        root->left = new BTNode('B');
        root->right = new BTNode('C');
        root->left->left = new BTNode('D');
        root->left->right = new BTNode('E');
        root->right->right = new BTNode('F');
        // Structure:      A
        //               /   \
        //              B     C
        //             / \     \
        //            D   E     F
    }

    // Verify Full Binary Tree Corollary
    void verifyCorollary() {
        int nodes = countNodes(root);
        int emptySubtrees = countEmptySubtrees(root);
        cout << "Nodes: " << nodes << endl;
        cout << "Empty Subtrees: " << emptySubtrees << endl;
        cout << "Corollary (Empty Subtrees = Nodes + 1): " 
             << (emptySubtrees == nodes + 1 ? "Verified" : "Not Verified") << endl;
    }

    ~BinaryTree() {
        deleteTree(root);
    }
};

int main() {
    BinaryTree tree;
    tree.createSampleTree();
    tree.verifyCorollary();
    return 0;
}
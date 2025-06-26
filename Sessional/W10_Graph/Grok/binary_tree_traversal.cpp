#include <iostream>
using namespace std;

// Binary tree node structure
struct BTNode {
    char data;
    BTNode *left, *right;
    BTNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    BTNode* root;

    // Helper functions for traversals
    void preorder(BTNode* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(BTNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void postorder(BTNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    // Helper function to delete tree
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

    // Public traversal methods
    void printPreorder() {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void printInorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void printPostorder() {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    ~BinaryTree() {
        deleteTree(root);
    }
};

int main() {
    BinaryTree tree;
    tree.createSampleTree();
    tree.printPreorder();
    tree.printInorder();
    tree.printPostorder();
    return 0;
}
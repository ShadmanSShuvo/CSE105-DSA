#include <iostream>
#include <queue>
using namespace std;

// Binary tree node structure
struct BTNode {
    char data;
    BTNode *left, *right;
    BTNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    BTNode* root;

    // Recursive traversals
    void preorder(BTNode* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(BTNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void postorder(BTNode* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Level order traversal using queue
    void levelOrder() {
        if (!root) return;
        queue<BTNode*> q;
        q.push(root);
        while (!q.empty()) {
            BTNode* node = q.front();
            q.pop();
            cout << node->data << " ";
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
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

    // Create sample binary tree
    void createSampleTree() {
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

    // Public traversal methods
    void printPreorder() { cout << "Preorder: "; preorder(root); cout << endl; }
    void printInorder() { cout << "Inorder: "; inorder(root); cout << endl; }
    void printPostorder() { cout << "Postorder: "; postorder(root); cout << endl; }
    void printLevelOrder() { cout << "Level Order: "; levelOrder(); cout << endl; }

    ~BinaryTree() { deleteTree(root); }
};

int main() {
    BinaryTree tree;
    tree.createSampleTree();
    tree.printPreorder();
    tree.printInorder();
    tree.printPostorder();
    tree.printLevelOrder();
    return 0;
}
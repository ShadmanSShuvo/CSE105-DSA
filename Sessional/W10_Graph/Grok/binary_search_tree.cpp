#include <iostream>
using namespace std;

struct BSTNode {
    int key;
    BSTNode *left, *right, *parent;
    BSTNode(int k) : key(k), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinarySearchTree {
    BSTNode* root;

    // Recursive search
    BSTNode* treeSearch(BSTNode* node, int k) {
        if (!node || node->key == k) return node;
        if (k < node->key) return treeSearch(node->left, k);
        return treeSearch(node->right, k);
    }

    // Inorder traversal
    void inorder(BSTNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    // Delete tree
    void deleteTree(BSTNode* node) {
        if (!node) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Insert node
    void insert(int k) {
        BSTNode* newNode = new BSTNode(k);
        if (!root) {
            root = newNode;
            return;
        }
        BSTNode* current = root;
        BSTNode* parent = nullptr;
        while (current) {
            parent = current;
            if (k <= current->key) current = current->left;
            else current = current->right;
        }
        newNode->parent = parent;
        if (k <= parent->key) parent->left = newNode;
        else parent->right = newNode;
    }

    // Search for key
    bool search(int k) {
        return treeSearch(root, k) != nullptr;
    }

    void printInorder() { cout << "Inorder: "; inorder(root); cout << endl; }

    ~BinarySearchTree() { deleteTree(root); }
};

int main() {
    BinarySearchTree bst;
    // Insert keys: 6, 5, 7, 2, 8
    bst.insert(6);
    bst.insert(5);
    bst.insert(7);
    bst.insert(2);
    bst.insert(8);
    // Structure:      6
    //               / \
    //              5   7
    //             /     \
    //            2       8
    bst.printInorder();
    cout << "Search 7: " << (bst.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 3: " << (bst.search(3) ? "Found" : "Not Found") << endl;
    return 0;
}
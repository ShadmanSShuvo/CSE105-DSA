#include <iostream>
using namespace std;

// General tree node structure
struct TreeNode {
    char data;
    TreeNode *left, *rightsibling, *parent;
    TreeNode(char val) : data(val), left(nullptr), rightsibling(nullptr), parent(nullptr) {}
};

class GeneralTree {
    TreeNode* root;

    // Preorder traversal
    void preorder(TreeNode* node) {
        if (!node) return;
        cout << node->data << " ";
        TreeNode* child = node->left;
        while (child) {
            preorder(child);
            child = child->rightsibling;
        }
    }

    // Delete tree
    void deleteTree(TreeNode* node) {
        if (!node) return;
        TreeNode* child = node->left;
        while (child) {
            TreeNode* next = child->rightsibling;
            deleteTree(child);
            child = next;
        }
        delete node;
    }

public:
    GeneralTree() : root(nullptr) {}

    // Create sample general tree
    void createSampleTree() {
        root = new TreeNode('A');
        TreeNode* b = new TreeNode('B'); b->parent = root;
        TreeNode* c = new TreeNode('C'); c->parent = root;
        TreeNode* d = new TreeNode('D'); d->parent = root;
        root->left = b;
        b->rightsibling = c;
        c->rightsibling = d;
        TreeNode* e = new TreeNode('E'); e->parent = b;
        b->left = e;
        TreeNode* f = new TreeNode('F'); f->parent = c;
        TreeNode* g = new TreeNode('G'); g->parent = c;
        c->left = f;
        f->rightsibling = g;
        // Structure:      A
        //               /|\
        //              B C D
        //             / / \
        //            E F   G
    }

    void printPreorder() { cout << "Preorder: "; preorder(root); cout << endl; }

    ~GeneralTree() { deleteTree(root); }
};

int main() {
    GeneralTree tree;
    tree.createSampleTree();
    tree.printPreorder();
    return 0;
}
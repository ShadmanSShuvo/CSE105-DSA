#include <iostream>
#include <vector>
using namespace std;

struct Node {
    char data;
    vector<Node*> children;

    Node(char val) : data(val) {}
};

class Tree {
    Node* root;

public:
    Tree() : root(nullptr) {}

    // Create a sample tree
    void createSampleTree() {
        root = new Node('c');
        root->children.push_back(new Node('a'));
        root->children.push_back(new Node('d'));
        Node* e = new Node('e');
        e->children.push_back(new Node('b'));
        e->children.push_back(new Node('f'));
        root->children.push_back(e);
    }

    // Preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        for (Node* child : node->children)
            preorder(child);
    }

    void printPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    ~Tree() {
        // Proper cleanup would require recursive deletion
    }
};

int main() {
    Tree t;
    t.createSampleTree();
    t.printPreorder();
    return 0;
}
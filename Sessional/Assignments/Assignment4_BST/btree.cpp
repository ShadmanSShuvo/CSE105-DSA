#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert a node into BST
Node* insert(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

// In-order traversal (LNR)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Pre-order traversal (NLR)
void preorder(Node* root) {
    if (root) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (LRN)
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

// Level-order (Breadth-First Search)
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";

        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}

// Height of the tree
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Find minimum value node
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// Delete a node from BST
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // One or no child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Search a key
bool search(Node* root, int key) {
    if (!root) return false;

    if (key == root->data) return true;
    else if (key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

// Pretty print tree structure (2D sideways)
void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == nullptr) return;

    space += indent;

    printTree(root->right, space);

    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->data << "\n";

    printTree(root->left, space);
}

// Driver code
int main() {
    Node* root = nullptr;

    // Insert some data
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
        root = insert(root, val);

    cout << "In-order: ";
    inorder(root); cout << endl;

    cout << "Pre-order: ";
    preorder(root); cout << endl;

    cout << "Post-order: ";
    postorder(root); cout << endl;

    cout << "Level-order: ";
    levelOrder(root); cout << endl;

    cout << "Height: " << height(root) << endl;

    cout << "\nTree Structure:\n";
    printTree(root);

    // Delete node and print again
    int key = 70;
    root = deleteNode(root, key);
    cout << "\nAfter deleting " << key << ", Tree Structure:\n";
    printTree(root);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class CompleteBinaryTree {
    vector<int> tree; // 1-based indexing

public:
    CompleteBinaryTree() {
        tree.push_back(0); // Dummy value at index 0
    }

    // Insert node
    void insert(int value) {
        tree.push_back(value);
    }

    // Get parent index
    int parent(int i) {
        if (i <= 1 || i >= tree.size()) return -1;
        return i / 2;
    }

    // Get left child index
    int leftChild(int i) {
        int left = 2 * i;
        return left < tree.size() ? left : -1;
    }

    // Get right child index
    int rightChild(int i) {
        int right = 2 * i + 1;
        return right < tree.size() ? right : -1;
    }

    // Print tree level order
    void printLevelOrder() {
        cout << "Level Order: ";
        for (size_t i = 1; i < tree.size(); ++i) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CompleteBinaryTree tree;
    // Insert nodes: 1, 2, 3, 4, 5, 6, 7
    tree.insert(1); // Root
    tree.insert(2); // Left of 1
    tree.insert(3); // Right of 1
    tree.insert(4); // Left of 2
    tree.insert(5); // Right of 2
    tree.insert(6); // Left of 3
    tree.insert(7); // Right of 3
    // Structure:     1
    //               / \
    //              2   3
    //             / \ / \
    //            4  5 6  7
    tree.printLevelOrder();
    cout << "Parent of node 5: " << tree.parent(5) << endl;
    cout << "Left child of node 2: " << tree.leftChild(2) << endl;
    cout << "Right child of node 2: " << tree.rightChild(2) << endl;
    return 0;
}
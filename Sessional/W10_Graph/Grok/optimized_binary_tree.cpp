#include <iostream>
#include <variant>
using namespace std;

// Node types: Leaf (operand) or Internal (operator)
struct LeafNode {
    int operand;
    LeafNode(int val) : operand(val) {}
};

struct InternalNode {
    char op; // Operator: +, -, *, /
    void* left;  // Pointer to either InternalNode or LeafNode
    void* right;
    InternalNode(char o) : op(o), left(nullptr), right(nullptr) {}
};

class OptimizedBinaryTree {
    using Node = variant<LeafNode, InternalNode*>;
    Node root;

    // Evaluate expression tree
    int evaluate(const Node& node) {
        if (holds_alternative<LeafNode>(node)) {
            return get<LeafNode>(node).operand;
        }
        InternalNode* internal = get<InternalNode*>(node);
        int leftVal, rightVal;
        if (internal->left && holds_alternative<LeafNode>(*reinterpret_cast<Node*>(internal->left))) {
            leftVal = get<LeafNode>(*reinterpret_cast<Node*>(internal->left)).operand;
        } else {
            leftVal = evaluate(*reinterpret_cast<Node*>(internal->left));
        }
        if (internal->right && holds_alternative<LeafNode>(*reinterpret_cast<Node*>(internal->right))) {
            rightVal = get<LeafNode>(*reinterpret_cast<Node*>(internal->right)).operand;
        } else {
            rightVal = evaluate(*reinterpret_cast<Node*>(internal->right));
        }
        switch (internal->op) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return rightVal != 0 ? leftVal / rightVal : throw runtime_error("Division by zero");
            default: throw runtime_error("Invalid operator");
        }
    }

    // Preorder traversal
    void preorder(const Node& node) {
        if (holds_alternative<LeafNode>(node)) {
            cout << get<LeafNode>(node).operand << " ";
            return;
        }
        InternalNode* internal = get<InternalNode*>(node);
        cout << internal->op << " ";
        if (internal->left) preorder(*reinterpret_cast<Node*>(internal->left));
        if (internal->right) preorder(*reinterpret_cast<Node*>(internal->right));
    }

    // Delete tree
    void deleteTree(Node& node) {
        if (holds_alternative<InternalNode*>(node)) {
            InternalNode* internal = get<InternalNode*>(node);
            if (internal->left) {
                Node* child = reinterpret_cast<Node*>(internal->left);
                deleteTree(*child);
                if (holds_alternative<InternalNode*>(*child)) delete get<InternalNode*>(*child);
                else delete child;
            }
            if (internal->right) {
                Node* child = reinterpret_cast<Node*>(internal->right);
                deleteTree(*child);
                if (holds_alternative<InternalNode*>(*child)) delete get<InternalNode*>(*child);
                else delete child;
            }
        }
    }

public:
    OptimizedBinaryTree() {}

    // Create sample expression tree: (3 + 5) * 2
    void createSampleTree() {
        InternalNode* mult = new InternalNode('*');
        InternalNode* plus = new InternalNode('+');
        mult->left = new Node(plus);
        mult->right = new Node(LeafNode(2));
        plus->left = new Node(LeafNode(3));
        plus->right = new Node(LeafNode(5));
        root = Node(mult);
        // Structure:      *
        //               / \
        //              +   2
        //             / \
        //            3   5
    }

    void printPreorder() { cout << "Preorder: "; preorder(root); cout << endl; }
    int evaluate() { return evaluate(root); }

    ~OptimizedBinaryTree() { deleteTree(root); }
};

int main() {
    OptimizedBinaryTree tree;
    tree.createSampleTree();
    tree.printPreorder();
    cout << "Result: " << tree.evaluate() << endl;
    return 0;
}
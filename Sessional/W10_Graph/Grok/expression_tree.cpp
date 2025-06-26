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
    InternalNode* left;
    InternalNode* right;
    InternalNode(char o) : op(o), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
    // Use variant to store either LeafNode or InternalNode
    using Node = variant<LeafNode, InternalNode*>;
    Node root;

    // Evaluate expression tree
    int evaluate(const Node& node) {
        if (holds_alternative<LeafNode>(node)) {
            return get<LeafNode>(node).operand;
        }
        InternalNode* internal = get<InternalNode*>(node);
        int leftVal = evaluate(*internal->left);
        int rightVal = evaluate(*internal->right);
        switch (internal->op) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': return rightVal != 0 ? leftVal / rightVal : throw runtime_error("Division by zero");
            default: throw runtime_error("Invalid operator");
        }
    }

    // Preorder traversal for printing
    void preorder(const Node& node) {
        if (holds_alternative<LeafNode>(node)) {
            cout << get<LeafNode>(node).operand << " ";
            return;
        }
        InternalNode* internal = get<InternalNode*>(node);
        cout << internal->op << " ";
        preorder(*internal->left);
        preorder(*internal->right);
    }

    // Delete tree
    void deleteTree(Node& node) {
        if (holds_alternative<InternalNode*>(node)) {
            InternalNode* internal = get<InternalNode*>(node);
            if (internal->left) { deleteTree(*internal->left); delete internal->left; }
            if (internal->right) { deleteTree(*internal->right); delete internal->right; }
        }
    }

public:
    ExpressionTree() {}

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

    ~ExpressionTree() { deleteTree(root); }
};

int main() {
    ExpressionTree tree;
    tree.createSampleTree();
    tree.printPreorder();
    cout << "Result: " << tree.evaluate() << endl;
    return 0;
}
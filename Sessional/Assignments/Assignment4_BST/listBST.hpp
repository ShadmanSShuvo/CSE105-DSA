#ifndef LISTBST_H
#define LISTBST_H

#include "BST.hpp"
#include <iostream>
#include <stdexcept>

/**
 * Binary Search Tree implementation using linked list structure
 * 
 * @tparam Key - The type of keys stored in the BST
 * @tparam Value - The type of values associated with keys
 */
template <typename Key, typename Value>
class ListBST : public BST<Key, Value> {
private:
    /**
     * Node class for the binary search tree
     */
    class Node {
    public:
        Key key;
        Value value;
        Node* left;
        Node* right;
        
        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    size_t node_count;
    
    // TODO: Implement private helper functions as needed
    // Start your private helper functions here
    // Helper function to recursively insert a node
    Node* insert_helper(Node* node, Key key, Value value) {
        if (!node) {
            node_count++;
            return new Node(key, value);
        }
        if (key < node->key) {
            node->left = insert_helper(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert_helper(node->right, key, value);
        } else {
            node->value = value; // Update value if key exists
        }
        return node;
    }
    
    // Helper function to find the node with minimum key
    Node* find_min_helper(Node* node) const {
        if (!node || !node->left) return node;
        return find_min_helper(node->left);
    }
    
    // Helper function to find the node with maximum key
    Node* find_max_helper(Node* node) const {
        if (!node || !node->right) return node;
        return find_max_helper(node->right);
    }
    
    // Helper function to recursively remove a node
    Node* remove_helper(Node* node, Key key) {
        if (!node) return nullptr;
        if (key < node->key) {
            node->left = remove_helper(node->left, key);
        } else if (key > node->key) {
            node->right = remove_helper(node->right, key);
        } else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                node_count--;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                node_count--;
                return temp;
            } else {
                Node* min_node = find_min_helper(node->right);
                node->key = min_node->key;
                node->value = min_node->value;
                node->right = remove_helper(node->right, min_node->key);
            }
        }
        return node;
    }
    
    // Helper function to find a node
    Node* find_helper(Node* node, Key key) const {
        if (!node || node->key == key) return node;
        if (key < node->key) return find_helper(node->left, key);
        return find_helper(node->right, key);
    }
    
    // Helper function to clear the tree
    void clear_helper(Node* node) {
        if (!node) return;
        clear_helper(node->left);
        clear_helper(node->right);
        delete node;
    }
    
    // Helper functions for tree traversal
    void print_default_helper(Node* node) const {
        if (!node) return;
        std::cout << "(" << node->key << ":" << node->value;
        if (node->left || node->right) {
            std::cout << " ";
            if (node->left) print_default_helper(node->left);
            else std::cout << "()";
            std::cout << " ";
            if (node->right) print_default_helper(node->right);
            else std::cout << "()";
        }
        std::cout << ")";
    }
    
    void print_inorder_helper(Node* node) const {
        if (!node) return;
        print_inorder_helper(node->left);
        std::cout << "(" << node->key << ":" << node->value << ") ";
        print_inorder_helper(node->right);
    }
    
    void print_preorder_helper(Node* node) const {
        if (!node) return;
        std::cout << "(" << node->key << ":" << node->value << ") ";
        print_preorder_helper(node->left);
        print_preorder_helper(node->right);
    }
    
    void print_postorder_helper(Node* node) const {
        if (!node) return;
        print_postorder_helper(node->left);
        print_postorder_helper(node->right);
        std::cout << "(" << node->key << ":" << node->value << ") ";
    }
    // End your private helper functions here

public:
    /**
     * Constructor
     */
    ListBST() : root(nullptr), node_count(0) {}
    
    /**
     * Destructor
     */
    ~ListBST() {
        // TODO: Implement destructor to free memory
        clear();
        root = nullptr;
        node_count = 0;
    }
    
    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override {
        // TODO: Implement insertion logic
        Node* newNode = new Node(key, value);
        if (!root) {
            root = newNode;
            node_count++;
            return true; // Insertion successful
        }
        Node* current = root;
        Node* parent = nullptr;
        if(root->key == key) {
            return false; // Key already exists
        }
        while (current) {
            parent = current;
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                return false; // Key already exists
            }
        }
        // Insert the new node
        if (key < parent->key) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
        node_count++;
        return true; // Insertion successful
    }
    
    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override {
        // TODO: Implement removal logic
        if(key==root->key){
            Node* temp = root;
            Node* root2;
            root2 = root->right;
            root2->left = root->left;
            root->key = root2->key;
            root->value = root2->value;
            delete temp;
            delete root2;
            return true;
        }

        Node* curr = root;
        while (curr)
        {
            if(key<curr->key)
                curr = curr->right;
            else if (key>curr->key)
                curr = curr->left;
            else{
                Node* temp=curr->left;
                while (temp)
                {
                    if(temp->right)
                        temp = temp->right;
                    else{
                        curr->key = temp->key;
                        curr->value = temp->value;
                        delete temp;
                        return true;
                    }
                }
                temp = curr->right;
                while (temp)
                {
                    if(temp->left)
                        temp = temp->left;
                    else{
                        curr->key = temp->key;
                        curr->value = temp->value;
                        delete temp;
                        return true;
                    }
                }
                
            }
        }
        
    }
    
    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override {
        // TODO: Implement find logic
        if(key == root->key) {
            return true;
        }
        Node* current = root;
        while (current) {
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                return true; // Key found
            }
        }
        return false; // Key not found
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override {
        // TODO: Implement get logic

    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override {
        // TODO: Implement update logic

    }

    /**
     * Clear all elements from the BST
     */
    void clear() override {
        // TODO: Implement clear logic

    }
    
    /**
     * Get the number of keys in the BST
     */
    size_t size() const override {
        // TODO: Implement size logic
        return node_count;
    }
    
    /**
     * Check if the BST is empty
     */
    bool empty() const override {
        // TODO: Implement empty check logic
        return node_count == 0;
    }
    
    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override {
        // TODO: Implement find_min logic
        if (empty()) {
            throw std::runtime_error("BST is empty");
        }
        Node* current = root;
        while (current->left) {
            current = current->left;
        }
        return current->key;
    }
    
    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override {
        // TODO: Implement find_max logic
        if (empty()) {
            throw std::runtime_error("BST is empty");
        }
        Node* current = root;
        while (current->right) {
            current = current->right;
        }
        return current->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override {
        // TODO: Implement print logic
        switch (traversal_type)
        {
        case 'I':
            Node* current = root;
            if (!current) {
                std::cout << "Tree is empty.\n";
                return;
            }
            while(current) {
                // Inorder traversal logic
                if (current->left) {
                    current = current->left;
                } else {
                    std::cout << current->key << " ";
                    if (current->right) {
                        current = current->right;
                    } else {
                        break; // No right child, exit loop
                    }
                }
            }
            std::cout << "\n";
            // Inorder traversal
            break;
        case 'P':
            current = root;
            if (!current) {
                std::cout << "Tree is empty.\n";
                return;
            }
            while(current) {
                // Preorder traversal logic
                std::cout << current->key << " ";
                if (current->left) {
                    current = current->left;
                } else if (current->right) {
                    current = current->right;
                } else {
                    break; // No children, exit loop
                }
            }
            std::cout << "\n";
            // Preorder traversal
            break;
        case 'O':
            current = root;
            if (!current) {
                std::cout << "Tree is empty.\n";
                return;
            }
            while(current) {
                // Postorder traversal logic
                if (current->left) {
                    current = current->left;
                } else if (current->right) {
                    std::cout << current->key << " ";
                    current = current->right;
                } else {
                    std::cout << current->key << " ";
                    break; // No children, exit loop
                }
            }
            std::cout << "\n";
            // Postorder traversal
            break;
        case 'D':   
            current = root;
            if (!current) {
                std::cout << "Tree is empty.\n";
                return;
            }
            while(current) {
                // Default traversal logic (level-order)
                std::cout << current->key << " ";
                if (current->left) {
                    current = current->left;
                } else if (current->right) {
                    current = current->right;
                } else {
                    break; // No children, exit loop
                }
            }
            std::cout << "\n";
            // Default (level-order) traversal
            break;
        case 'C':
            current = root;
            if (!current) {
                std::cout << "Tree is empty.\n";
                return;
            }
            while(current) {
                // Level-order traversal logic with colors
                std::cout << current->key << " ";
                if (current->left) {
                    current = current->left;
                } else if (current->right) {
                    current = current->right;
                } else {
                    break; // No children, exit loop
                }
            }
            std::cout << "\n";
            // Level-order traversal (with colors)
        default:
            break;
        }
    }
    
};

#endif // LISTBST_H
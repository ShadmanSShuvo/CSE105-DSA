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
class ListBST : public BST<Key, Value>
{
private:
    /**
     * Node class for the binary search tree
     */
    class Node
    {
    public:
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
    };

    Node *root;
    size_t node_count;

    // TODO: Implement private helper functions as needed
    // Start your private helper functions here

    Node *insert_helper(Node *node, Key key, Value value)
    {
        if (!node)
        {
            node_count++;
            return new Node(key, value);
        }
        if (key < node->key)
        {
            node->left = insert_helper(node->left, key, value);
        }
        else if (key > node->key)
        {
            node->right = insert_helper(node->right, key, value);
        }
        else
        {
            return nullptr;
            // throw std::runtime_error("Insertion failed! Key already exists in BST,");

            // node->value = value; // Update value if key exists
        }
        return node;
    }

    Node *find_min_helper(Node *node) const
    {
        if (!node || !node->left)
            return node;
        return find_min_helper(node->left);
    }

    Node *find_max_helper(Node *node) const
    {
        if (!node || !node->right)
            return node;
        return find_max_helper(node->right);
    }

    Node *remove_helper(Node *node, Key key)
    {
        if (!node)
            return nullptr;
        if (key < node->key)
        {
            node->left = remove_helper(node->left, key);
        }
        else if (key > node->key)
        {
            node->right = remove_helper(node->right, key);
        }
        else
        {
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                node_count--;
                return temp;
            }
            else if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                node_count--;
                return temp;
            }
            else
            {
                Node *min_node = find_min_helper(node->right);
                node->key = min_node->key;
                node->value = min_node->value;
                node->right = remove_helper(node->right, min_node->key);
            }
        }
        return node;
    }

    Node *find_helper(Node *node, Key key) const
    {
        if (!node || node->key == key)
            return node;
        if (key < node->key)
            return find_helper(node->left, key);
        return find_helper(node->right, key);
    }

    void clear_helper(Node *node)
    {
        if (!node)
            return;
        clear_helper(node->left);
        clear_helper(node->right);
        delete node;
    }

    void print_default_helper(Node *node) const
    {
        if (!node)
            return;

        std::cout << "(" << node->key << ":" << node->value;
        if (node->left || node->right)
        {
            std::cout << " ";
            if (node->left)
                print_default_helper(node->left);
            else
                std::cout << "()";

            if (node->right)
                std::cout << " ";
            print_default_helper(node->right);
        }
        std::cout << ")";
    }

    void print_inorder_helper(Node *node) const
    {
        if (!node)
            return;

        print_inorder_helper(node->left);
        std::cout << "(" << node->key << ":" << node->value << ") ";
        print_inorder_helper(node->right);
    }

    void print_preorder_helper(Node *node) const
    {
        if (!node)
            return;

        std::cout << "(" << node->key << ":" << node->value << ") ";
        print_preorder_helper(node->left);
        print_preorder_helper(node->right);
    }

    void print_postorder_helper(Node *node) const
    {
        if (!node)
            return;

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
    ~ListBST()
    {
        // TODO: Implement destructor to free memory
        clear_helper(root);
        root = nullptr;
        node_count = 0;
    }

    /**
     * Insert a key-value pair into the BST
     */
    bool insert(Key key, Value value) override
    {
        // TODO: Implement insertion logic
        if (find(key))
            return false;
        root = insert_helper(root, key, value);
        return true;
    }

    /**
     * Remove a key-value pair from the BST
     */
    bool remove(Key key) override
    {
        // TODO: Implement removal logic
        if (find(key))
        {
            root = remove_helper(root, key);
            return true;
        }

        return false;
    }

    /**
     * Find if a key exists in the BST
     */
    bool find(Key key) const override
    {
        // TODO: Implement find logic
        if (find_helper(root, key))
            return true;
        return false;
    }

    /**
     * Find a value associated with a given key
     */
    Value get(Key key) const override
    {
        // TODO: Implement get logic
        Node *res = find_helper(root, key);
        if (res)
            return res->value;
        else
            throw std::runtime_error("Key not found");
    }

    /**
     * Update the value associated with a given key
     */
    void update(Key key, Value value) override
    {
        // TODO: Implement update logic
        Node *res = find_helper(root, key);
        if (res)
            res->value = value;
        else
            throw std::runtime_error("Key not found");
    }

    /**
     * Clear all elements from the BST
     */
    void clear() override
    {
        // TODO: Implement clear logic
        clear_helper(root);
    }

    /**
     * Get the number of keys in the BST
     */
    size_t size() const override
    {
        // TODO: Implement size logic
        return node_count;
    }

    /**
     * Check if the BST is empty
     */
    bool empty() const override
    {
        // TODO: Implement empty check logic
        return node_count == 0;
    }

    /**
     * Find the minimum key in the BST
     */
    Key find_min() const override
    {
        // TODO: Implement find_min logic
        if (!root)
            throw std::runtime_error("BST is empty");
        else
            return find_min_helper(root)->key;
    }

    /**
     * Find the maximum key in the BST
     */
    Key find_max() const override
    {
        // TODO: Implement find_max logic
        if (!root)
            throw std::runtime_error("BST is empty");
        else
            return find_max_helper(root)->key;
    }

    /**
     * Print the BST using specified traversal method
     */
    void print(char traversal_type = 'D') const override
    {
        // TODO: Implement print logic
        switch (traversal_type)
        {
        case 'D':
            std::cout << "BST (Default): ";
            if (!root)
                std::cout << "()";
            else
                print_default_helper(root);
            std::cout << std::endl;
            break;
        case 'I':
            std::cout << "BST (In-order): ";
            if (!root)
                std::cout << "()";
            else
                print_inorder_helper(root);
            std::cout << std::endl;
            break;

        case 'P':
            std::cout << "BST (Pre-order): ";
            if (!root)
                std::cout << "()";
            else
                print_preorder_helper(root);
            std::cout << std::endl;
            break;
        case 'O':
            std::cout << "BST (Post-order): ";
            if (!root)
                std::cout << "()";
            else
                print_postorder_helper(root);
            std::cout << std::endl;
            break;
        default:
            throw std::invalid_argument("Invalid traversal type");
            break;
        }
    }
};

#endif // LISTBST_H
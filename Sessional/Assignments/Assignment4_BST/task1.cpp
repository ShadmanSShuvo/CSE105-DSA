#include <iostream>
#include <fstream>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst) {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c) {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here
        switch (c)
        {
        case 'I':
            in_file >> val;
            bst->insert(val, val);
            break;
        
        case 'D':
            in_file >> val;
            bst->remove(val);
            break;

        case 'E':
            if(bst->empty()) {
                cout << "The BST is empty.\n";
            } else {
                cout << "The BST is not empty.\n";
            }
            break;
        case 'M':
            in_file >> str;
            if (str == "min" || str == "Min") {
                try {
                    cout << "Minimum: " << bst->find_min() << "\n";
                } catch (const runtime_error &e) {
                    cout << e.what() << "\n";
                }
            } else if (str == "max" || str == "Max") {
                try {
                    cout << "Maximum: " << bst->find_max() << "\n";
                } catch (const runtime_error &e) {
                    cout << e.what() << "\n";
                }
            } else {
                cout << "Invalid command: " << str << "\n";
            }
            break;
                

        case 'F':
            in_file >> val;
            if (bst->find(val)) {
                cout << "Found: " << val << "\n";
            } else {
                cout << "Not found: " << val << "\n";
            }
            break;
        
        case 'P':
            bst->print();
            break;
        
        case 'S':
            cout << "Size: " << bst->size() << "\n";
            break;
        case 'T':
            in_file >> str;
            if (str == "inorder" || str == "Inorder") {
                bst->print('I');
            } else if (str == "preorder" || str == "Preorder") {
                bst->print('P');
            } else if (str == "postorder" || str == "Postorder") {
                bst->print('O');
            } else if (str == "default" || str == "Default") {
                bst->print('D');
            } else {
                cout << "Invalid traversal type: " << str << "\n";
            }
            break;
        }
        // End your code here
    }
    in_file.close();
    delete bst;
    return 0;
}

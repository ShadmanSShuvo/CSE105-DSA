#include <iostream>
#include <fstream>
#include <string>
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
    char c;
    int val;
    string command;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst) {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c) {
        try {
            switch (c) {
                case 'F':
                    in_file >> val;
                    if (bst->find(val)) {
                        cout << "Key " << val << " found in BST." << endl;
                    } else {
                        cout << "Key " << val << " not found in BST." << endl;
                    }
                    break;
                case 'E':
                    if (bst->empty()) {
                        cout << "Empty" << endl;
                    } else {
                        cout << "Not Empty" << endl;
                    }
                    break;
                case 'I':
                    in_file >> val;
                    if (bst->insert(val, val)) {
                        cout << "Key " << val << " inserted into BST, ";
                        bst->print('D');
                    } else {
                        cout << "Insertion failed! Key " << val << " already exists in BST, ";
                        bst->print('D');
                    }
                    break;
                case 'M':
                    in_file >> command;
                    if (command == "Min") {
                        cout << "Minimum value: " << bst->find_min() << endl;
                    } else if (command == "Max") {
                        cout << "Maximum value: " << bst->find_max() << endl;
                    }
                    break;
                case 'D':
                    in_file >> val;
                    if (bst->remove(val)) {
                        cout << "Key " << val << " removed from BST, ";
                        bst->print('D');
                    } else {
                        cout << "Removal failed! Key " << val << " not found in BST, ";
                        bst->print('D');
                    }
                    break;
                case 'T':
                    in_file >> command;
                    if (command == "In") {
                        bst->print('I');
                    } else if (command == "Pre") {
                        bst->print('P');
                    } else if (command == "Post") {
                        bst->print('O');
                    }
                    break;
                case 'S':
                    cout << "Size: " << bst->size() << endl;
                    break;
            }
        } catch (const std::exception& e) {
            cout << e.what() << endl;
        }
    }
    in_file.close();
    delete bst;
    return 0;
}
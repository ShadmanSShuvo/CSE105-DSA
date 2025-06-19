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
        return 1;
    }

    BST<string, int> *bst1 = new ListBST<string, int>();
    if (!bst1) {
        cerr << "Memory allocation failed\n";
        return 2;
    }
    BST<string, int> *bst2 = new ListBST<string, int>();
    if (!bst2) {
        cerr << "Memory allocation failed\n";
        delete bst1;
        return 3;
    }

    int n;
    in_file >> n;
    string word;
    for (int i = 0; i < n; ++i) {
        in_file >> word;
        if (bst1->find(word)) {
            bst1->update(word, bst1->get(word) + 1);
        } else {
            bst1->insert(word, 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        in_file >> word;
        if (bst2->find(word)) {
            bst2->update(word, bst2->get(word) + 1);
        } else {
            bst2->insert(word, 1);
        }
    }

    cout << "Phil's words:" << endl;
    bst1->print('I');
    cout << "\nClaire's words:" << endl;
    bst2->print('I');
    cout << "\nGame starts!\n\n";
    cout << "==============================\n";

    while (in_file >> word) {
        bool phil_has_word = bst1->find(word);
        bool claire_has_word = bst2->find(word);
        
        if (phil_has_word) {
            cout << "Phil has " << word << "!" << endl;
            int count = bst1->get(word);
            if (count == 1) {
                bst1->remove(word);
            } else {
                bst1->update(word, count - 1);
            }
        }
        if (claire_has_word) {
            cout << "Claire has " << word << "!" << endl;
            int count = bst2->get(word);
            if (count == 1) {
                bst2->remove(word);
            } else {
                bst2->update(word, count - 1);
            }
        }
        
        if (bst1->empty() || bst2->empty()) {
            if (bst1->empty() && bst2->empty()) {
                cout << "\nTie!" << endl;
            } else if (bst1->empty()) {
                cout << "\nPhil's remaining words:" << endl;
                bst1->print('I');
                cout << "\nClaire's remaining words:" << endl;
                bst2->print('I');
                cout << "\n==============================\n";
                cout << "Phil wins!" << endl;
            } else {
                cout << "\nPhil's remaining words:" << endl;
                bst1->print('I');
                cout << "\nClaire's remaining words:" << endl;
                bst2->print('I');
                cout << "\n==============================\n";
                cout << "Claire wins!" << endl;
            }
            break;
        }

        cout << "\nPhil's remaining words:" << endl;
        bst1->print('I');
        cout << "\nClaire's remaining words:" << endl;
        bst2->print('I');
        cout << "\n==============================\n";
    }

    in_file.close();
    delete bst1;
    delete bst2;
    return 0;
}
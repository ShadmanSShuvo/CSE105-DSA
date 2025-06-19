#include <iostream>

#include <fstream>
#include "listBST.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file)
    {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    BST<int, int> *bst = new ListBST<int, int>();
    if (!bst)
    {
        cerr << "Memory allocation failed\n";
        return 3;
    }
    while (in_file >> c)
    {
        // TODO: Implement the logic to read commands from the file and output accordingly
        // After every insertion and removal, print the BST in nested parentheses format
        // Handle exceptions where necessary and print appropriate error messages

        // Start your code here
        try
        {
            switch (c)
            {
            case 'I':
                in_file >> val;
                if(bst->insert(val, val))
                    cout << "Key " << val << " inserted into BST, ";
                else
                    cout << "Insertion failed! Key " << val << " already exists in BST, ";
                     
                bst->print('D');
                break;

            case 'D':
                in_file >> val;
                if(bst->remove(val))
                    cout << "Key " << val << " removed from BST, ";
                else
                    cout << "Removal failed! Key " << val << " not found in BST, "; 
                
                bst->print('D');
                break;

            case 'E':
                if (bst->empty())
                {
                    cout << "Empty\n";
                }
                else
                {
                    cout << "Not empty\n";
                }
                break;
            case 'M':
                in_file >> str;
                if (strcmp(str, "min") == 0 || strcmp(str, "Min") == 0)
                {
                    try
                    {
                        cout << "Minimum value: " << bst->find_min() << "\n";
                    }
                    catch (const runtime_error &e)
                    {
                        cout << e.what() << "\n";
                    }
                }
                else if (strcmp(str, "max") == 0 || strcmp(str, "Max") == 0)
                {
                    try
                    {
                        cout << "Maximum value: " << bst->find_max() << "\n";
                    }
                    catch (const runtime_error &e)
                    {
                        cout << e.what() << "\n";
                    }
                }
                else
                {
                    cout << "Invalid command: " << str << "\n";
                }
                break;

            case 'F':
                in_file >> val;
                if (bst->find(val))
                {
                    cout << "Key " << val << " found in BST.\n";
                }
                else
                {
                    cout << "Key " << val << " not found in BST.\n";
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
                if (strcmp(str, "in") == 0 || strcmp(str, "In") == 0)
                {
                    bst->print('I');
                }
                else if (strcmp(str, "pre") == 0 || strcmp(str, "Pre") == 0)
                {
                    bst->print('P');
                }
                else if (strcmp(str, "post") == 0 || strcmp(str, "Post") == 0)
                {
                    bst->print('O');
                }
                else if (strcmp(str, "default") == 0 || strcmp(str, "Default") == 0)
                {
                    bst->print('D');
                }
                else
                {
                    cout << "Invalid traversal type: " << str << "\n";
                }
                break;
            }
        }catch (const std::exception& e) {
            cout << e.what() << endl;
        }

        // End your code here
    }
    in_file.close();
    delete bst;
    return 0;
}

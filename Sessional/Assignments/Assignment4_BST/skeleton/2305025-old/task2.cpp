#include <iostream>
#include <fstream>
#include <string>
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
        return 1;
    }

    BST<string, int> *bst1 = new ListBST<string, int>();
    if (!bst1)
    {
        cerr << "Memory allocation failed\n";
        return 2;
    }
    BST<string, int> *bst2 = new ListBST<string, int>();
    if (!bst2)
    {
        cerr << "Memory allocation failed\n";
        delete bst1; // Clean up previously allocated memory
        return 3;
    }

    int n;
    in_file >> n;
    string word;
    for (int i = 0; i < n; ++i)
    {
        // TODO: Implement the logic to read Phil's words
        // Start your code here

        in_file >> word;
        if (bst1->find(word))
            bst1->update(word, bst1->get(word) + 1);

        else
            bst1->insert(word, 1);

        // End your code here
    }
    for (int i = 0; i < n; ++i)
    {
        // TODO: Implement the logic to read Claire's words
        // Start your code here

        in_file >> word;
        if (bst2->find(word))
            bst2->update(word, bst2->get(word) + 1);

        else
            bst2->insert(word, 1);
        // End your code here
    }
    cout << "Phil's words:\n";
    bst1->print('I');
    cout << "\nClaire's words:\n";
    bst2->print('I');
    // TODO: Implement the logic to print the initial state of both hands
    // Start your code here

    // End your code here
    cout << "\nGame starts!\n\n";
    cout << "==============================\n";
    
        
    while (in_file >> word)
    {
        

        // TODO: Implement the logic to process the game turn and print both hands after each turn
        // Start your code here
        if (bst1->find(word))
        {
            cout << "Phil has " << word << "!\n";
            if (bst1->get(word) == 1)
                bst1->remove(word);
            else
                bst1->update(word, bst1->get(word) - 1);
        }
        if (bst2->find(word))
        {
            cout << "Claire has " << word << "!\n";
            if (bst2->get(word) == 1)
                bst2->remove(word);
            else
                bst2->update(word, bst2->get(word) - 1);
        }
        if(bst1->empty() && bst2->empty()){
            cout << "Tie!\n";
            break;
        }
        else if (bst1->empty())
        {
            cout << "Phil wins!\n";
            break;

        }
        else if (bst2->empty())
        {
            cout << "Claire wins!\n";
            break;
        }

        cout << "\nPhil's remaining words:\n";
        bst1->print('I');
        cout << "\nClaire's remaining words:\n";
        bst2->print('I');
        // End your code here
        cout << "\n==============================\n";
    }

    in_file.close();
    delete bst1;
    delete bst2;
    return 0;
}
#include <iostream>
#include "trees.h"

using namespace std;

enum Action {stopProgram = -1, exitProgram, addValue, removeValue, doesInclude, printLeft, printRight, printSpec};

int main()
{
    Tree mytree;
    mytree.head = NULL;
    Action act;
    while (act != -1)
    {
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add a value to binary tree" << endl;
        cout << "2 - remove a value from binary tree" << endl;
        cout << "3 - verify, does the tree contain a value" << endl;
        cout << "4 - print list LTR" << endl;
        cout << "5 - print list RTL" << endl;
        cout << "6 - special print list" << endl;
        cout << "So what? ";
        int val = 0;
        cin >> val;
        cout << endl;
        act = (Action)val;
        switch (act)
        {
        case exitProgram:
            removeTree(mytree.head);
            mytree.head = NULL;
            cout << "Goodbye";
            return 0;
            break;
        case addValue: cout << "\nWhat value do you want to add? ";
            cin >> val;
            addValueTree(val, mytree);
            cout << endl;
            break;
        case removeValue:
            cout << "\nWhat value do you want to delete? ";
            cin >> val;
            deleteValueTree(val, mytree);
            cout << endl;
            break;
        case doesInclude:
            cout << "\nWhat value do you want to check? ";
            cin >> val;
            bool isTrue;
            isTrue = doesTreeInclude(val, mytree);
            if (isTrue)
                cout << "Yes\n";
            else
                cout << "No\n";
            break;
        case printLeft:
            printTreeLeftToRight(mytree.head);
            break;
        case printRight:
            printTreeRightToLeft(mytree.head);
            break;
        case printSpec:
            printTreeSpecFormat(mytree.head);
            break;
        default: cout << "\nIncorrect action\n";
            break;
        }
    }
}


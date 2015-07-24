#include <iostream>
#include <cstdlib>
#include "tree.h"
using namespace std;

int main()
{
	int TreeKey[]={50,76,21,4,32,64,15,52,100,83,2,3,70,87,80,10,18,8,12,17,19};
	int SIZE = sizeof(TreeKey)/sizeof(TreeKey[0]);
    cBST myTree;
    int input = 0;
    cout << "Before adding number" << endl;
    myTree.printOrder();
    for(int i=0; i<SIZE; i++)
    {
		myTree.addLeaf(TreeKey[i]);
	}
	cout << "After adding number and print order" << endl;
	myTree.printOrder();
	cout << "\nAfter adding number and print PRE order: \n" << endl;
	myTree.printPreOrder();

    myTree.PrintChildren(TreeKey[5]);
    myTree.PrintChildren(71);
    cout << "Smallest key in tree is " << myTree.FindSmallestKey() << endl;


    cout << "\nEnter key to delete, enter -1 to exit\n";
    while(input!=-1)
    {
        cout << "---------------\n";
        cout << "Delete node: ";
        cin >> input;
        if(input!=-1)
        {
            cout << endl;
            myTree.RemoveNode(input);
            cout << "\nTree after rm \n";
            myTree.printOrder();
            cout << endl;
        }
    }
	return 0;
}

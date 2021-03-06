//CS 2C Lab 5 code
//This program implement splay tree with top-down splaying with inheritance
//Copyright © 2018 Hanzhuo Gong. All right reserved.

#include <iostream>
#include "FHsplayTree.h"
using namespace std;

template <typename Object>
class PrintObject
{
public:
	void operator()(Object obj)
	{
		cout << obj << " ";
	}
};

int main()
{
	int k;
	FHsplayTree<int> searchTree, testTree;
	//FHsearch_tree<int> searchTree;
	PrintObject<int> intPrinter;

	searchTree.traverse(intPrinter);
	cout << searchTree.showRoot() << endl;

	cout << "Initial size: " << searchTree.size() << endl;
	for (k = 1; k <= 32; k++)
		searchTree.insert(k);
	cout << "New size: " << searchTree.size() << endl;

	cout << "\nTraversal: \n";
	searchTree.traverse(intPrinter);
	cout << endl << endl;

	cout << "new root is:" << searchTree.showRoot() << endl;
	for (k = -1; k < 10; k++)
	{
		// searchTree.contains(k);  // alt to find() - different error return
		try
		{
			searchTree.find(k);
		}
		catch (...)
		{
			cout << " oops ";
		}
		cout << "splay " << k << " --> root: " << searchTree.showRoot()
			<< " height: " << searchTree.showHeight() << endl;
	}

	cout << "\n---------------------self testing---------------------" << endl;
	searchTree.insert(60);
	searchTree.insert(50);
	searchTree.insert(30);
	cout << "root is:" << searchTree.showRoot() << endl;

	searchTree.remove(30);
	cout << "new root is:" << searchTree.showRoot() << endl;
	searchTree.traverse(intPrinter);

	cout << "\n\n-----------Testing one node---------------" << endl;
	testTree.insert(30);
	cout << "Before remove, size is: " << testTree.size() << endl;
	cout << "root for test tree is:" << testTree.showRoot() << endl;
	testTree.remove(30);
	cout << "After remove, size is: " << testTree.size() << endl;
	cout << "new root for test tree is:" << testTree.showRoot() << endl;
	testTree.traverse(intPrinter);

	cout << "\n------------Testing for contains-------------" << endl;
	testTree.insert(1);
	testTree.insert(5);
	testTree.insert(9);
	cout << "test Tree size is: " << testTree.size() << "\n" << endl;
	for (int j = 0; j < 10; j++) {
		try
		{
			testTree.contains(j);
		}
		catch (...)
		{
			cout << " oops " ;
		}
		cout << "splay " << j << " --> root: " << testTree.showRoot()
			<< " height: " << testTree.showHeight() << endl;
	}

	cout << "\n------------Test contains for searchTree--------" << endl;
	for (int k = -1; k < 10; k++)
	{
		// searchTree.contains(k);  // alt to find() - different error return
		try
		{
			searchTree.contains(k);
		}
		catch (...)
		{
			cout << " oops ";
		}
		cout << "splay " << k << " --> root: " << searchTree.showRoot()
			<< " height: " << searchTree.showHeight() << endl;
	}
	return 0;

}

/*-----------------Output-----------------------------------
0
Initial size: 0
New size: 32

Traversal:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32

new root is:32
oops splay -1 --> root: 1 height: 16
oops splay 0 --> root: 1 height: 16
splay 1 --> root: 1 height: 16
splay 2 --> root: 2 height: 9
splay 3 --> root: 3 height: 6
splay 4 --> root: 4 height: 6
splay 5 --> root: 5 height: 5
splay 6 --> root: 6 height: 6
splay 7 --> root: 7 height: 6
splay 8 --> root: 8 height: 7
splay 9 --> root: 9 height: 8

---------------------self testing---------------------
root is:30
new root is:29
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 31 32 50 60

-----------Testing one node---------------
Before remove, size is: 1
root for test tree is:30
After remove, size is: 0
new root for test tree is:0

------------Testing for contains-------------
test Tree size is: 3

oops splay 0 --> root: 1 height: 2
splay 1 --> root: 1 height: 2
oops splay 2 --> root: 5 height: 1
oops splay 3 --> root: 1 height: 2
oops splay 4 --> root: 5 height: 1
splay 5 --> root: 5 height: 1
oops splay 6 --> root: 9 height: 2
oops splay 7 --> root: 5 height: 1
oops splay 8 --> root: 9 height: 2
splay 9 --> root: 9 height: 2

------------Test contains for searchTree--------
oops splay -1 --> root: 1 height: 6
oops splay 0 --> root: 1 height: 6
splay 1 --> root: 1 height: 6
splay 2 --> root: 2 height: 7
splay 3 --> root: 3 height: 8
splay 4 --> root: 4 height: 7
splay 5 --> root: 5 height: 8
splay 6 --> root: 6 height: 7
splay 7 --> root: 7 height: 7
splay 8 --> root: 8 height: 7
splay 9 --> root: 9 height: 8
Press any key to continue . . .
*/


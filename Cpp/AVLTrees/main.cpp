#include <iostream>
#include "BST.h"
#include <ctime>
#include <cstdlib>

void display(TreeItemType& anItem) {
    cout << anItem.getKey() << endl;
}

int main() {
    BinarySearchTree bst;
	BinarySearchTree avl;
	srand(time(NULL));
	
	for(int i=0;i<500;i++){
		int rand_int = rand();
		bst.searchTreeInsert(rand_int);
		avl.AVLTreeInsert(rand_int);
	}
	cout << "bst height = " << bst.rootHeight() << endl;
	cout << "avl height = " << avl.rootHeight() << endl;
    return 0;
}

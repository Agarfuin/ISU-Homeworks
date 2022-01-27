// *********************************************************
#include <iostream>
int BinarySearchTree::height() const
{
    return heightRecursive(root);
}

int BinarySearchTree::heightRecursive(TreeNode *root) const
{
    int left = 0, right = 0;
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        left = heightRecursive(root->leftChildPtr);
        right = heightRecursive(root->rightChildPtr);
        if(left > right)
            return left+1;
        else
            return right+1;
    }
}


void BinarySearchTree::AVLinsert(TreeNode *& nodePtr, const TreeItemType & item)
{
	if(nodePtr == NULL)
		nodePtr = new TreeNode(item, NULL, NULL);
	else{
		if(item.getKey()<nodePtr->item.getKey())
			AVLinsert(nodePtr->leftChildPtr, item);
		else
			AVLinsert(nodePtr->rightChildPtr, item);

		int balance = balanced(nodePtr);
		
		if(balance > 1 && item.getKey() < nodePtr->leftChildPtr->item.getKey())
        	SRightRotation(nodePtr);

		if(balance < -1 && item.getKey() > nodePtr->rightChildPtr->item.getKey())
			SLeftRotation(nodePtr);

		if(balance > 1 && item.getKey() > nodePtr->leftChildPtr->item.getKey())
			DLeftRightRotation(nodePtr);

		if(balance < -1 && item.getKey() < nodePtr->rightChildPtr->item.getKey())
			DRightLeftRotation(nodePtr);
	}
}
	AVLinsert(root, newItem);

	if(nodePtr == NULL)
		return 0;
	else if(nodePtr->leftChildPtr != NULL && nodePtr->rightChildPtr == NULL)
		return heightRecursive(nodePtr->leftChildPtr);
	else if(nodePtr->leftChildPtr == NULL && nodePtr->rightChildPtr != NULL)
		return -1*(heightRecursive(nodePtr->rightChildPtr));
	else
		return heightRecursive(nodePtr->leftChildPtr) - heightRecursive(nodePtr->rightChildPtr);
}

	TreeNode* leftSubtreeRoot;
	TreeNode* leftrightRoot;
	TreeNode* node2;
	node2 = nodePtr;
	leftSubtreeRoot = nodePtr->leftChildPtr;
	leftrightRoot = nodePtr->leftChildPtr->rightChildPtr;
	nodePtr = leftSubtreeRoot;
	nodePtr->rightChildPtr = node2;
	nodePtr->rightChildPtr->leftChildPtr = leftrightRoot;
}

void BinarySearchTree::SLeftRotation(TreeNode *& nodePtr){
	TreeNode* rightSubtreeRoot;
	TreeNode* rightleftRoot;
	TreeNode* node2;
	node2 = nodePtr;
	rightSubtreeRoot = nodePtr->rightChildPtr;
	rightleftRoot = nodePtr->rightChildPtr->leftChildPtr;
	nodePtr = rightSubtreeRoot;
	nodePtr->leftChildPtr = node2;
	nodePtr->leftChildPtr->rightChildPtr = rightleftRoot;
}

void BinarySearchTree::DRightLeftRotation(TreeNode *& nodePtr){
	TreeNode* rightSubtreeRoot;
	TreeNode* rightleftRoot;
	TreeNode* temp1;
	TreeNode* temp2;
	TreeNode* node2;
	node2 = nodePtr;
	temp1 = nodePtr->rightChildPtr->leftChildPtr->leftChildPtr;
	temp2 = nodePtr->rightChildPtr->leftChildPtr->rightChildPtr;
	rightSubtreeRoot = nodePtr->rightChildPtr;
	rightleftRoot = nodePtr->rightChildPtr->leftChildPtr;
	nodePtr = rightleftRoot;
	nodePtr->leftChildPtr = node2;
	nodePtr->rightChildPtr = rightSubtreeRoot;
	nodePtr->leftChildPtr->rightChildPtr = temp1;
	nodePtr->rightChildPtr->leftChildPtr = temp2;
}

void BinarySearchTree::DLeftRightRotation(TreeNode *& nodePtr){
	TreeNode* leftSubtreeRoot;
	TreeNode* leftrightRoot;
	TreeNode* temp1;
	TreeNode* temp2;
	TreeNode* node2;
	node2 = nodePtr;
	temp1 = nodePtr->leftChildPtr->rightChildPtr->leftChildPtr;
	temp2 = nodePtr->leftChildPtr->rightChildPtr->rightChildPtr;
	leftSubtreeRoot = nodePtr->leftChildPtr;
	leftrightRoot = nodePtr->leftChildPtr->rightChildPtr;
	nodePtr = leftrightRoot;
	nodePtr->leftChildPtr = leftSubtreeRoot;
	nodePtr->rightChildPtr = node2;
	nodePtr->leftChildPtr->rightChildPtr = temp1;
	nodePtr->rightChildPtr->leftChildPtr = temp2;
}

int BinarySearchTree::rootHeight(){
	return heightRecursive(root);
}


void BinarySearchTree::searchTreeRetrieve(KeyType searchKey,

void BinarySearchTree::retrieveItem(TreeNode *treePtr,

void BinarySearchTree::copyTree(TreeNode *treePtr,

void BinarySearchTree::destroyTree(TreeNode *& treePtr)

void BinarySearchTree::preorder(TreeNode *treePtr,

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rhs)
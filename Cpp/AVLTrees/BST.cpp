// *********************************************************// Implementation file BST.cpp.// *********************************************************#include "BST.h"     // header file#include <cstddef>   // definition of NULL
#include <iostream>BinarySearchTree::BinarySearchTree() : root(NULL){}  // end default constructorBinarySearchTree::BinarySearchTree(                               const BinarySearchTree& tree){   copyTree(tree.root, root);}  // end copy constructorBinarySearchTree::~BinarySearchTree(){   destroyTree(root);}  // end destructor
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
bool BinarySearchTree::isEmpty() const{   return (root == NULL);}  // end searchTreeIsEmpty

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
}void BinarySearchTree::AVLTreeInsert(const TreeItemType& newItem){
	AVLinsert(root, newItem);}
int BinarySearchTree::balanced(TreeNode* nodePtr){
	if(nodePtr == NULL)
		return 0;
	else if(nodePtr->leftChildPtr != NULL && nodePtr->rightChildPtr == NULL)
		return heightRecursive(nodePtr->leftChildPtr);
	else if(nodePtr->leftChildPtr == NULL && nodePtr->rightChildPtr != NULL)
		return -1*(heightRecursive(nodePtr->rightChildPtr));
	else
		return heightRecursive(nodePtr->leftChildPtr) - heightRecursive(nodePtr->rightChildPtr);
}
void BinarySearchTree::SRightRotation(TreeNode *& nodePtr){
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
void BinarySearchTree::searchTreeInsert(const TreeItemType& newItem){   insertItem(root, newItem);}  // end searchTreeInsertvoid BinarySearchTree::searchTreeDelete(KeyType searchKey)                                 throw(TreeException){   deleteItem(root, searchKey);}  // end searchTreeDeletevoid BinarySearchTree::searchTreeRetrieve(KeyType searchKey,                                                       TreeItemType& treeItem) const                                                       throw(TreeException){   // if retrieveItem throws a TreeException, it is   // ignored here and passed on to the point in the code   // where searchTreeRetrieve was called   retrieveItem(root, searchKey, treeItem);}  // end searchTreeRetrieve

void BinarySearchTree::searchTreeRetrieve(KeyType searchKey,                                                       TreeNode*& treeNode) const                                                       throw(TreeException){   // if retrieveItem throws a TreeException, it is   // ignored here and passed on to the point in the code   // where searchTreeRetrieve was called   retrieveItem(root, searchKey, treeNode);}  // end searchTreeRetrievevoid BinarySearchTree::preorderTraverse(FunctionType visit){   preorder(root, visit);}  // end preorderTraversevoid BinarySearchTree::inorderTraverse(FunctionType visit){   inorder(root, visit);}  // end inorderTraversevoid BinarySearchTree::postorderTraverse(FunctionType visit){   postorder(root, visit);}  // end postorderTraversevoid BinarySearchTree::insertItem(TreeNode *& treePtr, const TreeItemType& newItem) throw(TreeException){   if (treePtr == NULL)   {  // position of insertion found; insert after leaf      // create a new node      treePtr = new TreeNode(newItem, NULL, NULL);   }   // else search for the insertion position   else if (newItem.getKey() < treePtr->item.getKey())      // search the left subtree      insertItem(treePtr->leftChildPtr, newItem);   else  // search the right subtree      insertItem(treePtr->rightChildPtr, newItem);}  // end insertItemvoid BinarySearchTree::deleteItem(TreeNode *& treePtr,                                  KeyType searchKey)                                  throw(TreeException)// Calls: deleteNodeItem.{   if (treePtr == NULL)      throw TreeException("TreeException: delete failed");  // empty tree   else if (searchKey == treePtr->item.getKey())      // item is in the root of some subtree      deleteNodeItem(treePtr);  // delete the item   // else search for the item   else if (searchKey < treePtr->item.getKey())      // search the left subtree      deleteItem(treePtr->leftChildPtr, searchKey);   else  // search the right subtree      deleteItem(treePtr->rightChildPtr, searchKey);}  // end deleteItemvoid BinarySearchTree::deleteNodeItem(TreeNode *& nodePtr)// Algorithm note: There are four cases to consider://   1. The root is a leaf.//   2. The root has no left child.//   3. The root has no right child.//   4. The root has two children.// Calls: processLeftmost.{   TreeNode     *delPtr;   TreeItemType replacementItem;   // test for a leaf   if ( (nodePtr->leftChildPtr == NULL) &&        (nodePtr->rightChildPtr == NULL) )   {  delete nodePtr;      nodePtr = NULL;   }  // end if leaf   // test for no left child   else if (nodePtr->leftChildPtr == NULL)   {  delPtr = nodePtr;      nodePtr = nodePtr->rightChildPtr;      delPtr->rightChildPtr = NULL;      delete delPtr;   }  // end if no left child   // test for no right child   else if (nodePtr->rightChildPtr == NULL)   {  delPtr = nodePtr;      nodePtr = nodePtr->leftChildPtr;      delPtr->leftChildPtr = NULL;      delete delPtr;   }  // end if no right child   // there are two children:   // retrieve and delete the inorder successor   else   {  processLeftmost(nodePtr->rightChildPtr,                      replacementItem);      nodePtr->item = replacementItem;   }  // end if two children}  // end deleteNodeItemvoid BinarySearchTree::processLeftmost(TreeNode *& nodePtr, TreeItemType& treeItem){   if (nodePtr->leftChildPtr == NULL)   {  treeItem = nodePtr->item;      TreeNode *delPtr = nodePtr;      nodePtr = nodePtr->rightChildPtr;      delPtr->rightChildPtr = NULL;  // defense      delete delPtr;   }   else      processLeftmost(nodePtr->leftChildPtr, treeItem);}  // end processLeftmostvoid BinarySearchTree::retrieveItem(TreeNode *treePtr,                                    KeyType searchKey,                                    TreeItemType& treeItem) const                                    throw(TreeException){   if (treePtr == NULL)      throw TreeException("TreeException: searchKey not found");   else if (searchKey == treePtr->item.getKey())      // item is in the root of some subtree      treeItem = treePtr->item;   else if (searchKey < treePtr->item.getKey())   // search the left subtree      retrieveItem(treePtr->leftChildPtr,                   searchKey, treeItem);   else  // search the right subtree      retrieveItem(treePtr->rightChildPtr,                          searchKey, treeItem);}  // end retrieveItem

void BinarySearchTree::retrieveItem(TreeNode *treePtr,                                    KeyType searchKey,                                    TreeNode*& treeNode) const                                    throw(TreeException){   if (treePtr == NULL)      throw TreeException("TreeException: searchKey not found");   else if (searchKey == treePtr->item.getKey())      // item is in the root of some subtree      treeNode = treePtr;   else if (searchKey < treePtr->item.getKey())   // search the left subtree      retrieveItem(treePtr->leftChildPtr,                   searchKey, treeNode);   else  // search the right subtree      retrieveItem(treePtr->rightChildPtr,                          searchKey, treeNode);}  // end retrieveItem

void BinarySearchTree::copyTree(TreeNode *treePtr,                          TreeNode *& newTreePtr) const{   // preorder traversal   if (treePtr != NULL)   {  // copy node      newTreePtr = new TreeNode(treePtr->item, NULL, NULL);      copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);      copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);   }   else      newTreePtr = NULL;  // copy empty tree}  // end copyTree

void BinarySearchTree::destroyTree(TreeNode *& treePtr){   // postorder traversal   if (treePtr != NULL)   {  destroyTree(treePtr->leftChildPtr);      destroyTree(treePtr->rightChildPtr);      delete treePtr;      treePtr = NULL;   }  // end if}  // end destroyTree

void BinarySearchTree::preorder(TreeNode *treePtr,                          FunctionType visit){   if (treePtr != NULL)   {  visit(treePtr->item);      preorder(treePtr->leftChildPtr, visit);      preorder(treePtr->rightChildPtr, visit);   } // end if}  // end preordervoid BinarySearchTree::inorder(TreeNode *treePtr,                         FunctionType visit){   if (treePtr != NULL)   {  inorder(treePtr->leftChildPtr, visit);      visit(treePtr->item);      inorder(treePtr->rightChildPtr, visit);   } // end if}  // end inordervoid BinarySearchTree::postorder(TreeNode *treePtr,                           FunctionType visit){   if (treePtr != NULL)   {  postorder(treePtr->leftChildPtr, visit);      postorder(treePtr->rightChildPtr, visit);      visit(treePtr->item);   } // end if}  // end postorder

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree& rhs){   if (this != &rhs)   {  destroyTree(root);  // deallocate left-hand side      copyTree(rhs.root, root);  // copy right-hand side   }  // end if   return *this;}  // end operator=// Implementations of copyTree, destroyTree, preorder,// inorder, postorder, setRootPtr, rootPtr, getChildPtrs,// setChildPtrs, and the overloaded assignment operator are// the same as for the ADT binary tree.// End of implementation file.
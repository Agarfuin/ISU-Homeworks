// *********************************************************

   int height() const;
   int heightRecursive(TreeNode *root) const;

   virtual void searchTreeRetrieve(KeyType searchKey,

   virtual void AVLTreeInsert(const TreeItemType& newItem);
   virtual int rootHeight();
   void SRightRotation(TreeNode *& nodePtr);
   void SLeftRotation(TreeNode *& nodePtr);
   void DRightLeftRotation(TreeNode *& nodePtr);
   void DLeftRightRotation(TreeNode *& nodePtr);
   int balanced(TreeNode* nodePtr);
   
   void retrieveItem(TreeNode *treePtr, KeyType searchKey,
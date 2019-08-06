/*Given a Binary Search Tree and two integers k1 and k2, 
find and print the elements which are in range k1 and k2 
(both inclusive).
Print the elements in increasing order. */

//For printing in increasing order, we need to do inorder
//traversal of BST

//APPROACH1: unoptimized : O(n) 

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
   if (root==NULL){
     return ;
   }
  int maxk = max(k1,k2) ;
  int mink = min(k1,k2) ;

  elementsInRangeK1K2(root->left,k1,k2);
   if (root->data>=mink&&root->data<=maxk)
    cout<<root->data<<" ";
   
   elementsInRangeK1K2(root->right,k1,k2);


}

//APPROACH2: Optimized : three possibilities:
//root in range, root less than k1, root greater than k2
//if in range - perform in inorder manner

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
    if (root == NULL){
        return;
    }
    if (root->data >= k1 && root->data <= k2){
        elementsInRangeK1K2(root->left, k1, k2);
        cout<<root->data<<" ";
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else if (root->data < k1){
        elementsInRangeK1K2(root->right, k1, k2);
    }
    else{
        elementsInRangeK1K2(root->left, k1, k2);
    }
}

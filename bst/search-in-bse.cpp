/*Given a BST and an integer k. Find if the integer k is 
present in given BST or not. Return the node with data k 
if it is present, return null otherwise.
Assume that BST contains all unique elements. */
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
    if (root == NULL){
        return NULL;
    }
    if (root->data == k){
        return root;
    }
    else if (k > root->data){
        return searchInBST(root->right, k);
    }
    else{
        return searchInBST(root->left, k);
    }
}
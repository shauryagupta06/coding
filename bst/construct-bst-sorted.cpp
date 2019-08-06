/*Given a sorted integer array A of size n which contains 
all unique elements. You need to construct a balanced BST 
from this input array. Return the root of constructed BST.
Note : If array size is even, take first mid as root. */

//As it should be balanced, we take middle element of
//array as root, then we calll for left and right subtrees

BinaryTreeNode<int>* Helper(int *input, int si, int ei){
    if (si > ei){
        return NULL;
    }
    int mid = (si + ei)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(input[mid]);
    root->left = Helper(input, si, mid - 1);
    root->right = Helper(input, mid + 1, ei);
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
    return Helper(input, 0, n - 1);
}
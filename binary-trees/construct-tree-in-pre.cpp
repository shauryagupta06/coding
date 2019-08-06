/*Given Preorder and Inorder traversal of a binary tree, 
create the binary tree associated with the traversals.You 
just need to construct the tree and return the root. */

BinaryTreeNode<int>* Helper(int* preorder, int* inorder, int preS, int preE, int inS, int inE){
    if (preS > preE){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preS]);
    int rootId = -1;
    for (int i = 0; i <= inE; i++){
        if (preorder[preS] == inorder[i]){
            rootId = i;
            break;
        }
    }
    int lpreS, lpreE, linS, linE, rpreS, rpreE, rinS, rinE;
    linS = inS;
    linE = rootId - 1;
    lpreS = preS + 1;
    lpreE = lpreS + (linE - linS);
    rpreS = lpreE + 1;
    rpreE = preE;
    rinS = rootId + 1;
    rinE = inE;
    BinaryTreeNode<int>* leftChild = Helper(preorder, inorder, lpreS, lpreE, linS, linE);
    BinaryTreeNode<int>* rightChild = Helper(preorder, inorder, rpreS, rpreE, rinS, rinE);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return Helper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);

}

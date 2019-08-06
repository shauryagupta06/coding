/*Given Postorder and Inorder traversal of a binary tree, 
create the binary tree associated with the traversals.You 
just need to construct the tree and return the root. */

BinaryTreeNode<int>* Helper(int *postorder, int *inorder, int postS, int postE, int inS, int inE){
    if (postS > postE){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postorder[postE]);
    int rootId = -1;
    for (int i = inS; i <= inE; i++){
        if (postorder[postE] == inorder[i]){
            rootId = i;
            break;
        }
    }
    int lpostS, lpostE, linS, linE, rpostS, rpostE, rinS, rinE;
    linS = inS;
    linE = rootId - 1;
    lpostS = postS;
    lpostE = lpostS + (linE - linS);
    rinS = rootId + 1;
    rinE = inE;
    rpostS = lpostE + 1;
    rpostE = postE - 1;
    root->left = Helper(postorder, inorder, lpostS, lpostE, linS, linE);
    root->right = Helper(postorder, inorder, rpostS, rpostE, rinS, rinE);
    return root;
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength) {
    return Helper(postorder, inorder, 0, postLength - 1, 0, inLength - 1);

}

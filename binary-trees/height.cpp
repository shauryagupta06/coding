/*Return height of BT */
//base case is necessary
int height(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;

}
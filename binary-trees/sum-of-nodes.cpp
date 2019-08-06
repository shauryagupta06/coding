//Return sum of all nodes of BT
int sumOfAllNodes(BinaryTreeNode<int>* root) {
    if (!root){
        return 0;
    }
    return sumOfAllNodes(root->left) + sumOfAllNodes(root->right) + root->data;
}

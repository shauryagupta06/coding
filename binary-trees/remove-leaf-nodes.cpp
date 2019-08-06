//Remove all leaf nodes, one must free the memory also 
//of the deleted nodes

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if (root == NULL){
        return NULL;
    }
    if (!root->left && !root->right){
        delete root;
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}

//Print all nodes which do not have a sibling

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL){
        return;
    }
    if (!root->left && !root->right){
        return;
    }
    if (!root->left && root->right){
        cout<<root->right->data<<endl;
    }
    else if (!root->right){
        cout<<root->left->data<<endl;
    }
    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);
}

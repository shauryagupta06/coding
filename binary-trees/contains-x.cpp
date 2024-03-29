/*Given a Binary Tree and an integer x, check
 if node with data x is present in the input binary 
 tree or not. Return true or false */
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if (root == NULL){
        return false;
    }
    if (root->data == x){
        return true;
    }
    if (isNodePresent(root->left, x)){
        return true;
    }
    if (isNodePresent(root->right, x)){
        return true;
    }
    return false;
}
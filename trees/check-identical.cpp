/*Given two Generic trees, return true if they are structurally identical 
i.e. they are made of nodes with the same values arranged in the same way. */
bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if ((root1 == NULL && root2 != NULL) || (root2 == NULL && root1 != NULL)){
        return false;
    }
    if (root1 == NULL && root2 == NULL){
        return true;
    }
    if (root1->data != root2->data){
        return false;
    }
    if (root1->children.size() != root2->children.size()){
        return false;
    }
    for (int i = 0; i < root1->children.size(); i++){
        if (!isIdentical(root1->children[i], root2->children[i])){
            return false;
        }
    }
    return true;
}

//Return ture if tree contains x
//else false

//if root is x, return true, else, check for all children
//if any child is true, return true, else keep checking
//for other children
//if no child returns true, then return false
bool containsX(TreeNode<int>* root, int x) {
    if (root == NULL){
        return false;
    }
    if (root->data == x){
        return true;
    }
    for (int i = 0; i < root->children.size(); i++){
        if (containsX(root->children[i], x)){
            return true;
        }
    }
    return false;
}
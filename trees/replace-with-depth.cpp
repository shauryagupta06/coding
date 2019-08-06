//In a given Generic Tree, replace each node with its depth 
//value. You need to just update the data of each node, no 
//need to return or print anything.

void Helper(TreeNode<int> *root, int depth){
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++){
        Helper(root->children[i], depth + 1);
    }
}
void replaceWithDepthValue(TreeNode<int> *root){    
    Helper(root, 0);

}
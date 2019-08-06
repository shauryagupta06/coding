//Return no. of leaf nodes in generic tree
//if empty tree, ans = 0
//if only root, ans = 1
//else ans is sum of leaf nodes of all children subtrees 

#include<vector>
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data){
        this -> data = data;
    }
};
int numLeafNodes(TreeNode<int>* root) {
    if (root == NULL){
        return 0;
    }
    if (root->children.empty()){
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++){
        ans += numLeafNodes(root->children[i]);
    }
    return ans;
}
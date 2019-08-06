//Return height of generic tree, empty tree, height = 0
//only one node (root), height = 1

//Find child with max height, root's 
//height is h = maxheight + 1, return h
//if leaf node, it should return 1

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
int height(TreeNode<int>* root) {
    if (root == NULL){
        return 0;
    }
    int h = 1;
    for (int i = 0; i < root->children.size(); i++){
        int childAns = height(root->children[i]);
        if (childAns + 1 > h){
            h = childAns + 1;
        }
    }
    return h;
}

//Return node with max data in generic tree

//Note: root == NULL case only for empty tree, 
//not needed as the base case because there will no call
//after leaf node as it won't enter for loop and make no
//further calls, return itself 

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
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if (root == NULL){
        return NULL;
    }
    TreeNode<int>* maxNode = root;
    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int>* childAns = maxDataNode(root->children[i]);
        if (maxNode->data < childAns->data){
            maxNode = childAns;
        }
    }
    return maxNode;
    
}
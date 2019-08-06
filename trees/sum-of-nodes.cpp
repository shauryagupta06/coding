//Always see tree as a recursive tree ie. root and its children subtrees 
//get sum of sum of nodes of all subtrees and add root data to it, then return 

//Note: here we do not need base case because, at leaf node, it will not 
//go inside for loop, make no further calls, return ans i.e. root data
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
int sumOfNodes(TreeNode<int>* root) {
    int sum = root->data;
    for(int i = 0; i < root->children.size(); i++){
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}
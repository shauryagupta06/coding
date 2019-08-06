//Given a generic tree and an integer n. Find and return 
//the node with next larger element in the Tree i.e. find 
//a node with value just greater than n.

//set ans as root if root is greater than n
//because root is possible ans, else ans = NULL
//check for childAns, if it is not NULL and it
//is smaller, then it is better than ans, update ans

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    if (root == NULL){
        return NULL;
    }
    TreeNode<int>* ans = NULL;
    if (root->data > n){
        ans = root;
    }
    for (int i = 0; i < root->children.size(); i++){
        TreeNode<int>* childAns = nextLargerElement(root->children[i], n);
        if (ans && childAns){
            if (childAns->data < ans->data){
                ans = childAns;
            }
        }
        if (!ans){
            ans = childAns;
        }
    }
    return ans;
}
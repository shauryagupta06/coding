//Given a tree and an integer x, 
//find and return the number of Nodes which
//are greater than x

//count ans as 1 if self is greater than x
//else, keep ans = 0
//return sum of self and all children 

//Note: Recurive is always DFS

int nodesGreaterThanX(TreeNode<int> *root, int x) {
    if (root == NULL){
        return 0;
    }
    int ans = 0;
    if (root->data > x){
        ans = 1;
    }
    for (int i = 0; i < root->children.size(); i++){
        ans += nodesGreaterThanX(root->children[i], x);
    }
    return ans;
}




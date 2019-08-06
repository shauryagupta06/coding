//Given a tree, find and return the node for 
//which sum of data of all children 
//and the node itself is maximum. In the sum, 
//data of node itself and data of immediate children 
//is to be taken.

//DFS - Recursive 
class MaxNode{
    public:
    TreeNode<int>* Node;
    int sum;
    MaxNode(){}
    MaxNode(TreeNode<int> *x){
        this->Node = x;
        int s = x->data;
        for (int i = 0; i < x->children.size(); i++){
            s += x->children[i]->data;
        }
        this->sum = s;
    }
};
MaxNode Helper(TreeNode<int> *root){
    if (root == NULL){
        MaxNode ans;
        ans.Node = NULL;
        ans.sum = 0;
        return ans;
    }
    MaxNode ans(root);
    for (int i = 0; i < root->children.size(); i++){
        MaxNode childAns = Helper(root->children[i]);
        if (childAns.sum > ans.sum){
            ans = childAns;
        }
    }
    return ans;
}
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    return Helper(root).Node;
}

//BFS: Using queue
class MaxNode{
    public:
    TreeNode<int>* Node;
    int sum;
};
TreeNode<int>* maxSumNode(TreeNode<int> *root){
    if (root == NULL){
        return NULL;
    }
    MaxNode ans;
    ans.sum = 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();
        int fsum = front->data;
        for (int i = 0; i < front->children.size(); i++){
            fsum += front->children[i]->data;
            q.push(front->children[i]);
        }
        if (fsum > ans.sum){
            ans.Node = front;
            ans.sum = fsum;
        }
    }
    return ans.Node;
}

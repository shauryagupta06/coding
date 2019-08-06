/*Given a generic tree, find and return the node with 
second largest value in given tree. Return NULL if no 
node with required value is present. */

//APPROACH1: Priority queue
//Take a queue for BFS and a min priority queue pq
//Consider tree as array, do BFS traversal
//Add first two elements - root and its first child
//in priority queue. 
//Take out a front from q, if it is greater than
//top of pq(smallest in pq), then it has a place in top 2
//pop pq and push front
//after BFS, pq has top two elements of tree in it
//if both are same elements, then the tree has only 1 element
//ans should be NULL, else return pq.top(): 2nd largest element

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    if (root == NULL || root->children.empty()){
        return NULL;
    }
    queue<TreeNode<int>*> q;
    priority_queue<TreeNode<int>*, vector<TreeNode<int>*>, greater<TreeNode<int>*>> pq;
    q.push(root);
    pq.push(root);
    pq.push(root->children[0]);
    while (!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        if (front->data > pq.top()->data){
            pq.pop();
            pq.push(front);
        }
        for(int i = 0; i < front->children.size(); i++){
            q.push(front->children[i]);
        }
    }
    TreeNode<int>* ans = pq.top();
    pq.pop();
    if (ans->data == pq.top()->data){
        return NULL;
    }
    return ans;
}
//APPROACH2 : Taking two nodes and passing them
//to helper function by reference, if nort passed by
//reference, answer will be wrong as everytime a new pointer
//will be created with a different address
//O(n)

void Helper(TreeNode<int> *root, TreeNode<int>* &first, TreeNode<int>* &second){
    if (root == NULL){
        return;
    }
    if (!first){
        first = root;
    }
    else if (root->data > first->data){
        second = first;
        first = root;
    }
    else if (!second && root->data < first->data){
        second = root;
    }
    else if (second && root->data > second->data && root->data < first->data){
        second = root;
    }
  
    for (int i = 0; i < root->children.size(); i++){
        Helper(root->children[i], first, second);
    }
    return;
}
TreeNode <int>* secondLargest(TreeNode<int> *root) {
    TreeNode<int> *first = NULL;
    TreeNode<int> *second = NULL;
    Helper(root, first, second);
    return second;
}


/*Given a BST, convert it into a 
sorted linked list. Return the head of LL. */
class Pair{
    public:
    Node<int>* head;
    Node<int>* tail;
};
Pair Helper(BinaryTreeNode<int>* root){
    if (root == NULL){
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }
    Pair ans;
    Pair lans = Helper(root->left);
    Pair rans = Helper(root->right);
    Node<int>* rootLL = new Node<int>(root->data);
    if (!lans.head){
        ans.head = rootLL;
    }
    else{
        ans.head = lans.head;
        lans.tail -> next = rootLL;
    }
    if (!rans.head){
        ans.tail = rootLL;
    }
    else{
        ans.tail = rans.tail;
        rootLL->next = rans.head;
    }
    return ans;
}
Node<int>* constructBST(BinaryTreeNode<int>* root) {
    return Helper(root).head;
    
}
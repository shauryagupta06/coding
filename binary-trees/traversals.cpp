//Traversals can be DFS (recursive) or BFS (using queue)
//DFS Traversal for binary tree can be pre order 
//or post order or inorder
//eg.  5
//    / \
//   3   4
//  / \  
// 1   2
//BFS : 5 3 4 1 2  (level-wise)
//DFS : 5 3 1 2 4  (recursive)
//DFS(1): PreOrder : 5 3 1 2 4 (same as DFS recursive)
//DFS(2): InOrder : 1 3 2 5 4 (left then root then right)
//DFS(3): PostOrder : 1 2 3 4 5 
//(left then right then root)

#include <iostream>
using namespace std;
#include<queue>
template <typename T>
class BTNode{
    public:
    T data;
    BTNode* left;
    BTNode* right;
    BTNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
BTNode<int>* takeInputLevelWise(){
    int data;
    cin >> data;
    if (data == -1){
        return NULL;
    }
    BTNode<int>* root = new BTNode<int>(data);
    queue<BTNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<int>* front = q.front();
        q.pop();
        int leftd;
        cin >> leftd;
        if (leftd != -1){
            BTNode<int>* leftc = new BTNode<int>(leftd);
            front->left = leftc;
            q.push(leftc);
        }
        int rightd;
        cin >> rightd;
        if (rightd != -1){
            BTNode<int>* rightc = new BTNode<int>(rightd);
            front->right = rightc;
            q.push(rightc);
        }
    }
    return root;
}
//BFS Traversal
void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout<<front->data<<":";
        if (front->left){
            cout<<"L:"<<front->left->data<<",";
            q.push(front->left);
        }
        else{
            cout<<"L:"<<-1<<",";
        }
        if (front->right){
            cout<<"R:"<<front->right->data<<endl;
            q.push(front->right);
        }
        else{
            cout<<"R:"<<-1<<endl;
        }
    }
    return;
}
//DFS Traversal
void printTreeRecursive(BTNode<int>* root){
    if (root == NULL){
        return;
    }
    cout<<root->data<<":";
    if (root->left){
        cout<<"L"<<root->left->data;
    }
    if(root->right){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    printTreeRecursive(root->left);
    printTreeRecursive(root->right);
    
    return;
}
//DFS(1): PreOrder: same as PrintRecursive func but 
//here left and right children are not printed side by side
void preorder(BTNode<int>* root){
    if (root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
//DFS(2): InOrder : left then root then right
void inorder(BTNode<int>* root){
    if (root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//DFS(3): PreOrder: Print children then root 
void postorder(BTNode<int>* root){
    if (root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main() {
	TreeNode<int>* root = TakeInputLevel();
	preorder(root);
	cout<<endl;
	postorder(root);
	return 0;
}

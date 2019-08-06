//Traversals can be DFS (recursive) or BFS (using queue)
//DFS Traversal for generic tree can be pre order or post order 
//eg.  5
//    / \
//   3   4
//  / \  
// 1   2
//BFS : 5 3 4 1 2  (level-wise)
//DFS : 5 3 1 2 4  (recursive)
//DFS(1): PreOrder : 5 3 1 2 4 (same as DFS recursive)
//DFS(2): PostOrder : 1 2 3 4 5 
//(print all children first, then root, for every subtree)

#include <iostream>
using namespace std;
#include<vector>
#include<queue>
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data){
        this -> data = data;
    }
};
TreeNode<int>* TakeInputLevel(){
    int  data;
    cout << "Enter root"<<endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode<int> *front = q.front();
        q.pop();
        int n;
        cout<< "Enter no. of children"<<endl;
        cin >> n;
        for (int i = 0; i < n ;i++){
            int d;
            cout<<"Enter "<<i<<"th child of "<<front->data<<endl;
            cin >> d;
            TreeNode<int> *child = new TreeNode<int>(d);
            front->children.push_back(child);
            q.push(child);
        }
    }
    
    return root;
}
//BFS Traversal
void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode<int>* front = q.front();
        q.pop();
        cout<<front->data<<":";
        for (int i = 0; i < front->children.size(); i++){
            if (i != front->children.size()-1){
                cout<<front->children[i]->data<<",";
            }
            else{
                cout<<front->children[i]->data;
            }
            q.push(front->children[i]);
        }
        cout<<endl;
    }
}
//DFS Traversal
void PrintRecursive(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++){
        cout << root->children[i]->data <<" ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++){
        PrintRecursive(root->children[i]);
    }
}
//DFS(1): PreOrder: same as PrintRecursive func but 
//here children are not printed side by side
void preorder(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for (int i = 0; i < root->children.size(); i++){
        preorder(root->children[i]);
    }
}
////DFS(2): PostOrder: Print children then root 
void postorder(TreeNode<int>* root){
    if (root == NULL){
        return;
    }
    
    for (int i = 0; i < root->children.size(); i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}

int main() {
	TreeNode<int>* root = TakeInputLevel();
	preorder(root);
	cout<<endl;
	postorder(root);
	return 0;
}

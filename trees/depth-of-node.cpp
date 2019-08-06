//root is level/depth 0,immediate children of root level/depth 1
//eg.  5      <---level/depth = 0
//    / \
//   3   4    <---level/depth = 1
//  / \  
// 1   2      <---level/depth = 2

//ans for k = 2 : 1 2

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
/////////////////////////////////////////////////////
void printLevelK(TreeNode<int>* root, int k){
    if (root == NULL){
        return;
    }
    if (k == 0){
        cout << root->data <<" ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++){
        printLevelK(root->children[i], k - 1);
    }
}
//////////////////////////////////////////////////////
int main() {
	TreeNode<int>* root = TakeInputLevel();
	printLevelK(root, 2);
	return 0;
}

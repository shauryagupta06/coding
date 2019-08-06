//User has to input thhe tree level-wise. The printing will be also level-wise
//eg.  5
//    / \
//   3   4
//  / \  
// 1   2

//input : 5 (2) 3 4 (2) 1 2 (0) (0) (0)
//(n) represents number of children of the node just prior

//printing: 5 : 3, 4
//          3 : 1, 2
//          4 :
//          1 : 
//          2 : 

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
int main() {
	TreeNode<int>* root = TakeInputLevel();
	printLevelWise(root);
	return 0;
}

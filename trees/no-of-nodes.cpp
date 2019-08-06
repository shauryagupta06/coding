//Always see tree as a recursive tree ie. root and its children subtrees 
//get sum of count of no. of nodes of all subtrees and add 1 to it, then return 

//Note: here we do not need base case because, at leaf node, it will not 
//go inside for loop, make no further calls, return ans i.e. 1


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
////////////////////////////////////////////////////////////
int numNodes(TreeNode<int>* root){
    int ans = 1;
    for (int i = 0; i < root->children.size();i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}
///////////////////////////////////////////////////////////
int main() {
	TreeNode<int>* root = TakeInputLevel();
	cout << numNodes(root);
	return 0;
}

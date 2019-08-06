//User has to input thhe tree depth-wise. The printing will be also depth-wise
//eg.  5
//    / \
//   3   4
//  / \  
// 1   2

//input : 5 (2) 3 (2) 1 (0) 2 (0) 4 (0)
//(n) represents number of children of the node just prior

//printing: 5 : 3, 4
//          3 : 1, 2
//          1 :
//          2 : 
//          4 : 

#include <iostream>
using namespace std;
#include<vector>
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data){
        this -> data = data;
    }
};
TreeNode<int>* TakeInputRecursive(){
    int  data;
    cout << "Enter data"<<endl;
    cin >> data;
    TreeNode<int> *root = new TreeNode<int>(data);
    int n;
    cout<< "enter no. of children";
    cin >> n;
    for (int i = 0; i < n ;i++){
        root->children.push_back(TakeInputRecursive());
    }
    return root;
}
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
int main() {
	TreeNode<int>* root = TakeInputRecursive();
	PrintRecursive(root);
	return 0;
}

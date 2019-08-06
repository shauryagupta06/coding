//DFS Traversal with printing left and right child
//eg. 10 20 -1 30 -1 -1 40 70 12 -1 -1 -1 -1 
//printing: 10:L20R40
//          20:R30
//          30:
//          40:L70
//          70:L12
//          12:
//tree:          10
//             /    \
//           20     40
//            \     /
//            30   70
//                /
//               12


#include <iostream>
using namespace std;
template <typename T>
class BTNode{
    public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;
    BTNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
BTNode<int>* takeInputRecursive(){
    int data;
    cin >> data;
    if (data == -1){
        return NULL;
    }
    BTNode<int>* root = new BTNode<int>(data);
    BTNode<int>* leftc = takeInputRecursive();
    BTNode<int>* rightc = takeInputRecursive();
    root->left = leftc;
    root->right = rightc;
    return root;
}
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
int main() {
	 BTNode<int>* root = takeInputRecursive();
	 printTreeRecursive(root);
	return 0;
}

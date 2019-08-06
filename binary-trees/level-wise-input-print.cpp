//BFS Traversal with printing left and right child
//eg. 10 20 40 -1 30 70 -1 -1 -1 12 -1 -1 -1  
//printing: 10:L20R40
//          20:R30
//          40:L70
//          30:
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
int main() {
	 BTNode<int>* root = takeInputLevelWise();
	 printLevelWise(root);
	return 0;
}

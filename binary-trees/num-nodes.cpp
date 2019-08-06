//Return no. of nodes in BT
//here base case is important

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
int numNodes(BTNode<int>* root){
    if (root == NULL){
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}
int main() {
	 BTNode<int>* root = takeInputLevelWise();
	 cout<<numNodes(root);
	return 0;
}

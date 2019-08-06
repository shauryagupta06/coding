/*Given a binary tree, write code to create a separate linked
 list for each level. You need to return the array which 
 contains head of each level linked list. */

#include<queue>
#include<vector>
template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> q;
    vector<node<int>*> vec;
    q.push(root);
    q.push(NULL);
    node<int>* head = NULL;
    node<int>* tail = NULL;
    while (!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (!front){
            vec.push_back(head);
            if (q.empty()){
                break;
            }
            q.push(NULL);
            head = NULL;
            tail = NULL;
        }
        else{
            if (!head){
                head = new node<int>(front->data);
                tail = head;
            }
            else{
                tail->next = new node<int>(front->data);
                tail = tail->next;
            }
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
    return vec;
}

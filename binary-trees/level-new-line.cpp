//Print level wise, each at new line

//Using queue and NULL as indicator of level change
//to be inserted in queue
//Each time NULL is popped, we need to check
//if it the last NULL i.e. q is empty, then break
//if it is not the last NULL, then push a new NULL in q
//and print a new line
//Other working is same as level wise traversal

#include<queue>
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (!front){
            if (q.empty()) break;
            cout<<endl;
            q.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }
    }
}
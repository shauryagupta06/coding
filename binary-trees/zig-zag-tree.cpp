//APPROACH1: two stacks s1 and s2
//As stack is LIFO, the elements come out in opposite 
//order of which they are inserted in
//s1 will print left to right, so insertion in s1 R -> L
//s2 will print right to left, so insertion in s2 L -> R
//Loop until both are empty
//first empty s1, and keep inserting children to s2
//then empty s2, keep inserting children to s1
//print new line after both loops

void zigZagOrder(BinaryTreeNode<int> *root) {
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();
            cout<<top->data<<" ";
            if (top->left) s2.push(top->left);
            if (top->right) s2.push(top->right);
        }
        cout<<endl;
        while(!s2.empty()){
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();
            cout<<top->data<<" ";
            if (top->right) s1.push(top->right);
            if (top->left)  s1.push(top->left);
        }
        cout<<endl;
    }
}



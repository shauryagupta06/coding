//Def: a tree is balanced when:
//1. difference in heights of left and right subtree is atmost 1
//2. left subtree is balanced
//3. right subtree is balanced

//APPROACH1: Chech for 1st condition
//Then call recursion on left and right
//O(n.height) time 

//APPROACH2: Make a pair of int height and bool isBalanced
//Everytime we need to first call recursion to get
//left and right answers, calc height
//if anyone of isBalanced is false, return false
//else check for 1st condition, return true if it meets
//else false
//O(n)
int height(BinaryTreeNode<int> root){
    if (!root){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root) {
    if (!root){
        return true;
    }
    if (abs(height(root->left)) - height(root->right) > 1){
        return false;
    }
    return(isBalanced(root->left) && isBalanced(root->right));
}
#define ppi pair<int,bool>
#define mp make_pair
ppi Helper(BinaryTreeNode<int> *root){
    if (!root){
        ppi ans = mp(0, true);
        return ans;
    }
    ppi lans = Helper(root->left);
    ppi rans = Helper(root->right);
    ppi ans;
    int h = max(lans.first, rans.first) + 1;
    if (!lans.second || !rans.second){
        ans = mp(h, false);
    }
    else if (abs(lans.first - rans.first) <= 1){
        ans = mp(h, true);
    }
    else{
        ans = mp(h, false);
    }
    //cout<<root->data<<" "<<ans.first<<" "<<ans.second<<endl;
    return ans;
}
bool isBalanced(BinaryTreeNode<int> *root) {
    return Helper(root).second;

}

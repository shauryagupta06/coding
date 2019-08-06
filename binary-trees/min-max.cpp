/*Given a binary tree, find and return the min and max data
 value of given binary tree.
Return the output as an object of PairAns class, which is 
already created. */

// Following is the Binary Tree node structure
 
 // PairAns class -
 class PairAns {
    public :
        int min;
        int max;
 };
 
#include <limits.h>
PairAns minMax(BinaryTreeNode<int> *root) {
    if (!root){
        PairAns ans;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        return ans;
    }
    PairAns lans = minMax(root->left);
    PairAns rans = minMax(root->right);
    PairAns ans;
    ans.min = min(root->data, min(lans.min, rans.min));
    ans.max = max(root->data, max(lans.max, rans.max));
    return ans;
}

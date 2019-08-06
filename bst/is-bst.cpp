//For a binary tree to be BST, three conditions
//1. root should be between the range of maximum of
//left subtree and minimum of right subtree, i.e. all elements
//in the left subtree of root should be less than the root
//and all elements in the right subtree of the root be
//greater than the root
//2. left subtree should be a BST
//3. right subtree should be a BST

//APPROACH1: Create funcs minBST, maxBST and checkBST
//get the maximum of
//left subtree and minimum of right subtree
//check for all three conditions 
//O(n^2) time

#include <limits.h>
int minBST(BinaryTreeNode<int>* root){
    if (!root){
        return INT_MAX;
    }
    return min(root->data, min(minBST(root->left), minBST(root->right)));
}
int maxBST(BinaryTreeNode<int>* root){
    if (!root){
        return INT_MIN;
    }
    return max(root->data, max(maxBST(root->left), maxBST(root->right)));
}
bool isBST(BinaryTreeNode<int>* root){
    if (root == NULL){
        return true;
    }
    int leftMax = maxBST(root->left);
    int rightMin = minBST(root -> right);
    return (root->data > leftMax && root->data <= rightMin && isBST(root->left) && isBST(root->right));
}

//APPROACH2: create a class Triplet to return three members:
//isbst bool, minBST int, maxBST int
//in the helper function, return class object, no need
//to repeat calc of min and max again and again
//O(n) time 

class Triplet{
    public: 
    bool check;
    int min;
    int max;
};
Triplet Helper(BinaryTreeNode<int>* root){
    if (root == NULL){
        Triplet ans;
        ans.check = true;
        ans.min = INT_MAX;
        ans.max = INT_MIN;
        return ans;
    }
    Triplet ans;
    Triplet lans = Helper(root->left);
    Triplet rans = Helper(root->right);
    ans.min = min(root->data, min(lans.min, rans.min));
    ans.max = max(root->data, max(lans.max, rans.max));
    ans.check = (root->data > lans.max && root->data <= rans.min && lans.check && rans.check);
    return ans;
}
bool isBST(BinaryTreeNode<int>* root){
    return Helper(root).check;
}

//APPROACH3 : Pass a min, max starting from min = -infinity
//and max = +infinity, call to root, check if root lies 
//in range of min max, if yes then check for left subtree
//in range min to rootdata-1, and right subtree in range
//rootdata(considering equality) to max

//condition used: all elements
//in the left subtree of root should be less than the root
//and all elements in the right subtree of the root be
//greater than the root

//O(n) time

bool Helper(BinaryTreeNode<int> *root, int min, int max){
    if (root == NULL){
        return true;
    }
    if (root->data <= min || root->data > max){
        return false;
    }
    return (Helper(root->left, min, root->data - 1) && Helper(root->right, root->data, max));
}
bool isBST(BinaryTreeNode<int> *root){
    return Helper(root, INT_MIN, INT_MAX);
}
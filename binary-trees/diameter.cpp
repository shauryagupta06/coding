/*Diameter of a tree is the longest path from one leaf 
node to another */
//APPROACH1: Make two funcs height and diameter and
//return best of three options: 
//dia(left), dia(right), h(l) + h(r)+ 1

//Here all the work is repeated for every node
//O(n.height) time 

int height(BTNode<int>* root){
    if (!root){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int diameter(BTNode<int>* root){
    if (!root){
        return 0;
    }
    int option1 = height(root->left) + height(root->right) + 1;
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}

//APPROACH2: make a funstion which returns height and dia
//both in a pair, use this to calc root result
//O(n) because each node is called only once

ppi heightDiameter(BTNode<int>* root){
    if (root ==NULL){
        ppi ans;
        ans.first = 0;
        ans.second = 0;
        return ans;
    }
    ppi lans = heightDiameter(root -> left);
    ppi rans = heightDiameter(root -> right);
    int h = max(lans.first, rans.first) + 1;
    int dia = max(lans.first + rans.first + 1, max(lans.second, rans.second));
    ppi ans;
    ans.first = h;
    ans.second = dia;
    return ans;
    
}

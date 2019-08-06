//subarray is continuous part of array
//first we insert 0th element into trie
//set prevxor and gmax as 0th element
//then we traverse for 1 to n-1th elements
//for element arr[i], if we keep arr[i] as ending point of 
//our subarray, we explore all other options
//eg in 1 8 2 5
//i = 2, arr[i] = 2
//trie has entries 1=(1) and 9=(1^8) , we find best
//among (1^8^2) = newxor, check for newxor match
//currmax = better b/w (8^2)and (2)
//find better of newxor and currmax and update gmax
//i = 3, arr[i] = 5
//trie has entries 1=(1) and 9=(1^8) and 11=(1^8^2), 
//(1^8^2^5) = newxor, check for newxor match
//currmax = better b/w (8^2^5) and (2^5) and (5)
//find better of newxor and currmax and update gmax
//basically, for i, X' = max(newxor, currmax) is the max xor 
//subarray for subarray ending with arr[i] i.e. 
//arr[i] is included in my answer
//gmax is the max of all X's

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
class trieNode{
    public:
    trieNode* left;
    trieNode* right;
};
void insertTrie(int n, trieNode* head){
    trieNode* curr = head;
    for (int i = 31; i >= 0; i--){
        int b = (n >> i) & 1;
        if (b == 0){
            if(! curr-> left){
                curr->left = new trieNode();
            }
            curr = curr-> left;
        }
        else{
            if (!curr->right){
                curr -> right = new trieNode();
            }
            curr = curr -> right;
        }
    }
}
int findMaxXOR(int* arr, int size, trieNode* head ){
    insertTrie(arr[0], head);
    int prevxor = arr[0];
    int gmax = arr[0];
    int newxor;
    for (int i = 1; i < size; i++){
        int ele = arr[i];
        newxor = prevxor ^ arr[i];
        int currmax = 0;
        trieNode* curr = head;
        for(int j = 31; j >=0; j--){
            int b = (newxor >> j) & 1;
            if (b == 0){
                if (curr -> right){
                    currmax += pow(2,j);
                    curr = curr -> right;
                }
                else{
                    curr = curr -> left;
                }
            }
            else {
                if (curr -> left){
                    currmax += pow(2,j);
                    curr = curr -> left;
                }
                else{
                    curr = curr -> right;
                }
            }
        }
        gmax = max(gmax, max(currmax, newxor));
        insertTrie(newxor, head);
        prevxor = newxor;
    }
    return gmax;
}
int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    trieNode* head = new trieNode();
    cout <<  findMaxXOR(arr, n, head );
	return 0;
}

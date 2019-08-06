//We will construst a trie for all nos. converted to binary
//In trie node, left is 0 and right is 1
//for finding max pair in array arr of size n,
//first we insert all n in trie
//Inserting takes n elements takes n*log(2^32) because 
//maximum interger can have 32 bits (4 bytes)

//then traverse through arr one by one, find the best pair 
//for arr[i] by searching opposite bit in trie and
//stor result in currmax
//after every array element, update gmax if currmax is better

//eg. if we have 11 = (1011) in binary, 
//for j = 3, bit b = 1, search for 0, if present move left, 
//and update currmax by 1*2^j
//if not present, move right, do not update currmax because
//after xor this position will be 0*2^j
//for j = 2, bit b = 0, search for 1
//for j = 1, bit b = 1, search for 0
//for j = 0, bit b = 1, search for 0

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
    int gmax = INT_MIN;
    for (int i = 0; i < size; i++){
        int ele = arr[i];
        trieNode* curr = head;
        int currmax = 0;
        for(int j = 31; j >=0; j--){
            int b = (ele >> j) & 1;
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
        if (currmax > gmax){
            gmax = currmax;
        }
    }
    return gmax;
}
int main() {
    int arr[6] = {8, 1, 2, 15, 11 , 5 };
    trieNode* head = new trieNode();
    for (int i = 0; i < 6; i++){
        insertTrie(arr[i], head);
    }
    cout <<  findMaxXOR(arr, 6, head );
	return 0;
}

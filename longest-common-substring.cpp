//Given two strings X (size = n) and Y (size = m). The task is 
//to find the length of the longest common substring.
//eg. X = ABCDGH, Y = ACDGHR ans: 4, lcsubstring = CDGH

//Simple: Check for all substrings in X (takes n^2), whether 
//present in Y (takes n time though KMP pattern matching)
//Total time : O(n^2 * m)

//APPROACH 1: DP In a table of size (n*m): store 
//longest common suffix, eg, X = abgcd, Y = agcde for i = 3, j = 2,
//dp[i][j] stores length of lc suffix of abg and ag, i.e.
//dp[3][2] = 1, dp[5][4] = 3, dp[5][5] = 0(as no commom suffix)
//answer will be max of whole table dp.
//Here we keep a track max len in z and 
//corresponding substring in string vector ans
//O(n*m) time O(n*m) space 

#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int main() {
	int t; cin>>t;
	while (t--){
	    int n, m;
	    string x, y;
	    cin>>n>>m>>x>>y;
	    int** dp = new int*[n];
	    for (int i = 0; i < n; i++)
	        dp[i] = new int[m];
	        
	    int z = 0;
	    vector<string> ans;
	    
	    for (int i = 0; i < n; i++){
	        for (int j = 0; j < m; j++){
	            if (x[i] == y[j]){
	                if (i == 0 || j == 0)
	                    dp[i][j] = 1;
	                else
	                    dp[i][j] = dp[i - 1][j - 1] + 1;
	                if (dp[i][j] > z){
	                    z = dp[i][j];
	                    ans.clear();
	                    ans.push_back(x.substr(i - z + 1, z));
	                }
	                else if (dp[i][j] == z){
	                    ans.push_back(x.substr(i - z + 1, z));
	                }
	            }
	            else{
	                dp[i][j] = 0;
	            }
	        }
	        
	    }
	   cout<<z<<endl;
	   /*for (int i = 0; i < ans.size(); i++)
	       cout<<ans[i]<<endl;*/

	}
	return 0;
}

//APPROACH2: Suffix tree 
//Takes O(n+m) i.e. linear time

//A generalization : k-common substring problem.
//Given the set of strings {S_{1},...,S_{K}} 
//where |S_{i}|=n_{i}  and n is total no. of chars
//in all strings.
//Find for each 2 <= k <=K, the longest strings which occur as 
//substrings of at least k strings.

//The longest common substrings of a set 
//of strings can be found by building a generalized 
//suffix tree for the strings, and 
//then finding the deepest internal nodes which 
//have leaf nodes from all the strings in the subtree 
//below it. The figure on the right is the suffix tree 
//for the strings "ABAB", "BABA" and "ABBA", padded 
//with unique string terminators, to become "ABAB$0",
// "BABA$1" and "ABBA$2". The nodes representing "A", 
//"B", "AB" and "BA" all have descendant leaves from 
//all of the strings, numbered 0, 1 and 2.

//Building the suffix tree takes O(n) time 
//(if the size of the alphabet is constant). 
//If the tree is traversed from the bottom up with 
//a bit vector telling which strings are seen below 
//each node

//To be coded
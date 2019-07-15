/* Given two strings s and t of lengths m and n
 respectively, find the Edit Distance between the strings. 
 Edit Distance of two strings is minimum number of steps 
 required to make one string equal to other. In order to 
 do so you can perform following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character*/
/* eg. s = abc, t = dc , edit dist = 2 (min) 
(1) insert a (2) replace b to c */

//recursive solution O(3^max(n,m)) 
#include <iostream>
#include <vector>
using namespace std;

int editDistance(string s1, string s2){

    if (s1.size()==0 && s2.size()==0)
        return 0;
    else if (s1.size() == 0)
        return s2.size();
    else if (s2.size() == 0)
        return s1.size();
    
    int ans;
    if (s1[0] == s2[0])
        ans = editDistance(s1.substr(1), s2.substr(1));
    else{
        //delete first from s2
        int x = editDistance(s1, s2.substr(1));
        //insert matching char infront of s2
        int y = editDistance(s1.substr(1), s2);
        //replace first char of s2 such that it matches with s1
        int z = editDistance(s1.substr(1), s2.substr(1));
        //operation which gives the best result i.e. min
        ans = min(x,min(y,z)) + 1;
    }
    return ans;
}
//memoization , save in (m+1) x (n+1) 2D array 
//O(m * n) time O(m * n) space
int editDistance(string s1, string s2, int** output){

    if (s1.size()==0 || s2.size()==0)
        return max(s1.size(), s2.size());
    
    int m = s1.size();
    int n = s2.size();
    if (output[m][n] != -1)
        return output[m][n];
    
    
    int ans;
    if (s1[0] == s2[0])
        ans = editDistance(s1.substr(1), s2.substr(1), output);
    else{
        //delete first from s2
        int x = editDistance(s1, s2.substr(1), output) + 1;
        //insert matching char infront of s2
        int y = editDistance(s1.substr(1), s2, output) + 1;
        //replace first char of s2 such that it matches with s1
        int z = editDistance(s1.substr(1), s2.substr(1), output) + 1;
        //operation which gives the best result i.e. min
        ans = min(x,min(y,z));
    }
    output[m][n] = ans;
    return ans;
}
int editDistance(string s1, string s2){

    int m = s1.size();
    int n = s2.size();
    int** output = new int*[m+1];
    for (int i = 0; i <= m; i++){
        output[i] = new int[n+1];
        for (int j = 0; j <= n; j++)
            output[i][j] = -1;
    }
    return editDistance(s1, s2, output);
}
//DP bottom up approach 
//O(m * n) time O(m * n) space
int editDistance(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
    
    int** output = new int*[m+1];
    for (int i = 0; i<= m; i++)
        output[i] = new int[n+1];
    
    for (int i = 0; i <= m; i++)
        output[i][0] = i;
    
    for (int j = 1; j<= n; j++)
        output[0][j] = j;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j<=n; j++){
            int ans;
            if (s1[m - i] == s2[n - j])
                ans = output[i-1][j-1];
            else{
                int x = output[i-1][j] + 1;
                int y = output[i][j-1] + 1;
                int z = output[i-1][j-1] + 1;
                ans = min(x, min(y, z));
            }
            output[i][j] = ans;
        }
    }
    return output[m][n];

}
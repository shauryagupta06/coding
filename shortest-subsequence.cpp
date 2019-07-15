//Given two string S and V. Return the length of 
//shortest subsequence in S such that it is not a 
//subsequence in V.
//n = length of S, m = length of V

//eg1. S = babab, V = babba ,ss : aab, ans: 3
//eg2. S = babab, V = baabba ,ss : bbab or abab , ans: 4

//APPROACH: two calls :
//(1) s[0] not part of ss, send s(1..n) and v(0..n)
//(2) s[0] part of ss, send s(1..n) and v(i+1..n)
//where i is the index of first occurence of s[0] in v

//recursive O(2^n * n) time 
#include<bits/stdc++.h>
int solve(string S, string V, int si, int vi){
    if (si == S.length())
        return 1001;
    if (vi == V.length())
        return 1;
    
    int out1 = solve(S, V, si + 1, vi);
    int idx = -1;
    for (int i = vi; i < V.length(); i++){
        if (V[i] == S[si]){
            idx = i;
            break;
        }
    }
    if (idx == -1){
        return 1;
    }
    int out2 = solve(S, V, si + 1, idx + 1) + 1;
    return min(out1, out2);
}
int solve(string S,string V)
{
	return solve(S, V, 0, 0);
}

//IMPROVISATION: we make a table for every vi and si, where the 
//first occurence idx is to be found, size of where=(n*m)
//eg. for S = babab, V  = babba
//where[] = 0 2 2 3 -1
//          1 1 4 4 4
//          0 2 2 3 -1
//          1 1 4 4 4
//          0 2 2 3 -1
// -1 denotes S[si] char not found at or after vi
//Recursive soln Still give TLE O(2^n), extra space of O(n*m)

int solve(string S, string V, int si, int vi, int** where){
    if (si == S.length())
        return 1001;
    if (vi == V.length())
        return 1;
    
    int out1 = solve(S, V, si + 1, vi, where);
    int idx = where[si][vi];
    if (idx == -1){
        return 1;
    }
    int out2 = solve(S, V, si + 1, idx + 1, where) + 1;
    return min(out1, out2);
}
int solve(string S,string V)
{
    int n = S.length();
    int m = V.length();
    int** where = new int*[n];
    for (int i = 0; i < n; i++){
        where[i] = new int[m];
        for (int j = 0; j < m; j++)
            where[i][j] = -1;
    }
    for (int i = 0; i < n; i++){
        int p = 0;
        for (int j = 0; j < m; j++){
            if (S[i] == V[j]){
                for (int k = p; k <= j; k++){
                    where[i][k] = j;
                }
                p = j + 1;
            }
        }
    }

	return solve(S, V, 0, 0, where);
}

//Memoization , unique calls : n*m, so time: O(n*m)
//space: O(n*m) for output, O(n*m) for where
int solve(string S, string V, int si, int vi, int** where, int** output){
    if (si == S.length())
        return 1001;
    if (vi == V.length())
        return 1;
    
    if (output[si][vi] != -1)
        return output[si][vi];
    
    int out1 = solve(S, V, si + 1, vi, where, output);
    
    int idx = where[si][vi];
    if (idx == -1){
        return 1;
    }
    int out2 = solve(S, V, si + 1, idx + 1, where, output) + 1;
    
    int ans = min(out1, out2);
    output[si][vi] = ans;
    
    return ans;
}
int solve(string S,string V)
{
    int n = S.length();
    int m = V.length();
    
    int** output = new int*[n];
    for (int i = 0; i < n; i++){
        output[i] = new int[m];
        for (int j = 0; j < m; j++)
            output[i][j] = -1;
    }
    
    int** where = new int*[n];
    for (int i = 0; i < n; i++){
        where[i] = new int[m];
        for (int j = 0; j < m; j++)
            where[i][j] = -1;
    }
    for (int i = 0; i < n; i++){
        int p = 0;
        for (int j = 0; j < m; j++){
            if (S[i] == V[j]){
                for (int k = p; k <= j; k++){
                    where[i][k] = j;
                }
                p = j + 1;
            }
        }
    }

	return solve(S, V, 0, 0, where, output);
} 
//dynamic programming, unique calls:(n+1)*(m+1),so time: O(n*m)
//space: O(n*m) for output, O(n*m) for where
//size of output: (n+1)*(m+1) ,size of where: (n)*(m)


int solve(string S,string V)
{
    int n = S.length();
    int m = V.length();
    
    int** output = new int*[n + 1];
    for (int i = 0; i <= n; i++){
        output[i] = new int[m + 1];
    }
    
    int** where = new int*[n];
    for (int i = 0; i < n; i++){
        where[i] = new int[m];
        for (int j = 0; j < m; j++)
            where[i][j] = -1;
    }
    for (int i = 0; i < n; i++){
        int p = 0;
        for (int j = 0; j < m; j++){
            if (S[i] == V[j]){
                for (int k = p; k <= j; k++){
                    where[i][k] = j;
                }
                p = j + 1;
            }
        }
    }
    
    for (int j = 0; j <= m; j++)
        output[n][j] = 1001;
    for (int i = 0; i < n; i++)
        output[i][m] = 1;
    
    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            int out1 = output[i + 1][j];
            int idx = where[i][j];
            if (idx == -1){
                output[i][j] = 1;
            }
            else{
                int out2 = output[i + 1][idx + 1] + 1;
                output[i][j] = min(out1, out2);
            }
        }
    }
	return output[0][0];
}






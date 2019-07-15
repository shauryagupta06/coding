//return length of longest common subsequence between two strings

//brute-force-recursion -exponenetial

int LCS_1(string s, string t){
    if (s.size() == 0 || t.size() == 0)
        return 0;

    if (s[0] == t[0])
        return (1 + LCS_1(s.substr(1),t.substr(1)));
    else{
        int a = LCS_1(s.substr(1), t);
        int b = LCS_1(s, t.substr(1));
        return max(a,b);
    }
}

int LCS_2(string s, string t, int** output){
    int m = s.size();
    int n = t.size();
    if (m == 0 || n == 0)
        return 0;
    
    if (output[m][n] != -1)
        return output[m][n];
    
    int ans;
    if (s[0] == t[0])
        ans = 1 + LCS_2(s.substr(1), t.substr(1), output);
    else{
        int a = LCS_2(s.substr(1), t, output);
        int b = LCS_2(s, t.substr(1), output);
        int c = LCS_2(s.substr(1), t.substr(1), output);
        ans = max(a,max(b,c));
    }

    output[m][n] = ans;
    
    return ans;
}

int LCS_2(string s, string t){
    int m = s.size();
    int n = t.size();
    int** output = new int*[m+1];
    for (int i=0; i < m+1; i++){
        output[i] = new int[n];
        for (int j = 0; j < n+1; j++)
            output[i][j] = -1;
    }
    int ans = LCS_2(s, t, output);
    for (int i = 0; i < m+1; i++){
        for (int j = 0; j < n+1; j++){
            cout<< output[i][j]<<" ";
        }
        cout << endl;
        
    }
    return ans;
}
int main() {
    string s,t;
    cin>>s>>t;
    cout << LCS_2(s, t) ;
    return 0;
}

//Dynamic Programming - O(m*n) time O(m*n) space
#include <bits/stdc++.h>
using namespace std;
int LCS_3(string s, string t){
    int m = s.size();
    int n = t.size();
    
    int** output = new int*[m+1];
    for (int i=0; i < m+1; i++)
        output[i] = new int[n+1];
        
    for (int i = 0 ; i <= m; i++)
        output[i][0] = 0;
    
    for (int j = 1; j <= n; j++)
        output[0][j] = 0;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if (s[m - i] == t[n - j])
                output[i][j] = 1 + output[i-1][j-1];
            else{
                int a = output[i-1][j];
                int b = output[i][j-1];
                int c = output[i-1][j-1];
                output[i][j] = max(a,max(b,c));
            }
        }
    }
    return output[m][n];
        
}


int main() {
    string s,t;
    cin>>s>>t;
    cout << LCS_3(s, t) ;
    return 0;
}


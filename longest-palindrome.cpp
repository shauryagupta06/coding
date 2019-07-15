//print the longest palidrome in a given string
//eg. abaab ans: baab

//dymanic programming approach 
//O(n^2) time O(n^2) space 
//output[si][ei] = 1, if substring s(si...ei) is a palindrome
//else output[si][ei] = 0

//traverse output in length decreasing fashion
//i.e 0,4 | 0,3 - 1,4 | 0,2 - 1,3 - 2,4 ans so on
//break if palindrome found, print s(ans.si...ans.ei)
#include <bits/stdc++.h>
using namespace std;
void print(int** output, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        pair<int,int> ans;
        ans.first = -1;
        ans.second = -1;
        int** output = new int*[n];
        for (int i = 0; i < n; i++)
            output[i] = new int[n];
            
        for (int i = 0; i < n; i++){
            output[i][i] = 1;
            if (i + 1 < n ){
                if (s[i] == s[i + 1])
                    output[i][i + 1] = 1;
                else
                    output[i][i + 1] = 0;
            }
        }
        
        for (int i = 2; i < n; i++){
            for(int j = 0; j < n - i; j++){
                int si = j; 
                int ei = j + i;
                if (output[si + 1][ei - 1] == 1 && s[si] == s[ei])
                    output[si][ei] = 1;
                else
                    output[si][ei] = 0;
            }
        }
        
        for (int i = n; i >= 2; i--){
            for (int j = 0; j <= n - i; j++){
                int si = j;
                int ei = j + i - 1;
                if (output[si][ei] == 1){
                    ans.first = si;
                    ans.second = ei;
                    break;
                }
            }
            if (ans.first!= -1)
            break;
        }
        if (ans.first != -1)
            cout<<s.substr(ans.first, ans.second - ans.first + 1)<<endl;
        else
            cout<<s[0]<<endl;
    }
}

//APPROACH2: O(1) space O(n^2) time
//Odd palindrome: Fix a center and expand in both directions
//If no better oddp found, 
//return s[0]: first occ. of longest odd palindrome(len = 1)
//Even palindrome: Fix 2 centers and expand in both directions
//If no better evenp found, return empty string(len = 0)
//Print better palindrome

using namespace std;
string checkOdd(string s, int n){
    int si, ei;
    si = 0;
    ei = 0;
    for (int i = 1; i <= n - 2; i++){
        int j = i;
        int k = i;
        while (s[j - 1] == s[k + 1] && j - 1 >= 0 && k + 1 <= n - 1){
            j--;
            k++;
        }
        if ((k - j) > (ei - si)){
            si = j;
            ei = k;
        }
    }
    return s.substr(si, ei - si + 1);
}

string checkEven(string s, int n){
    int si = 0;
    int ei = 0;
    for( int i = 0; i <= n - 2; i++){
        int j = i;
        int k = i;
        if (s[i] == s[i + 1]){
            j = i;
            k = i + 1;
            while (s[j - 1] == s[k + 1] && j-1 >= 0 && k+1 <= n - 1){
                j--;
                k++;
            }
        }
        if (j != k && (k - j) > (ei - si)){
            si = j;
            ei = k;
        }
    }
    if (si != ei)
        return s.substr(si, ei - si + 1);
    else
        return s.substr(0, 0);
}

int main() {
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.size();
        string evenp, oddp;
        oddp = checkOdd(s, n);
        evenp = checkEven(s, n);
        if (oddp.size() > evenp.size())
            cout<<oddp<<endl;
        else 
            cout<<evenp<<endl;
    }
}
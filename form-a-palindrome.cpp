//Given a string str, the task is to find the 
//minimum number of characters to be inserted to convert 
//it to palindrome. insertions can be anywhere in between

//egs. 
//ab: ans = 1 i.e. bab
//aa: ans = 0 i.e. aa
//abcd: ans = 3 i.e. dcbabcd
//abcda: ans = 2 i.e. adcbcda: same as ans for bcd = a'bcd'a
//abcde: ans is 4 i.e. edcbabcde

//APPROACH1: Recursion O(2^n)
//Recursive relation: for s(0....n-1), length = n
//if first char = last char, ans = func(s(1...n-2))
//else ans = min(func(s(1...n-1), func(s(0...n-2))) + 1

//Explanation
//ghost characters are included eg.s = abac
//calls for aba and bac
//aba gives 0, bac makes two calls: ba and ac
//ba returns 1 : aba or bab 
//'ba'c = 'aba'c or 'bab'c,
//to form palindrome, add c: c'aba'c or c'bab'c
//ac returns 1 : aca or cac
//b'ac' = b'cac' or b'aca', 
//to form palindrome, add b: b'aca'b or b'cac'b
//so bac returns min(1, 1) + 1 = 2
//abac can be a palindrome in two ways:
//using aba call: c'aba'c , ans1 = 0 + 1 = 1
//using bac call: a'bcacb'a (take any one) ans2 = 2+1 = 3
//return min(1, 3) = 1 , palindrome: 'c'abac

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int formPalindrome(string s, int n){
    if (n == 1 || n == 0 )
        return 0;
    
    if (s[0] == s[n-1])
        return formPalindrome(s.substr(1,n-2), n - 2);
    else{
        int ans1 = formPalindrome(s.substr(1), n - 1);
        int ans2 = formPalindrome(s.substr(0,n-1), n - 1);
        return min(ans1, ans2) + 1;
    }
}
int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    cout<<formPalindrome(s, n)<<endl;
	}
	return 0;
}

//APPROACH2 : DP O(n^2) time , O(n^2) space
//dp of size (n)*(n) 
//dp[i][j], starting index = i, ending index = j
//dp[i][j] is the min no. of insertions needed
//to make subtring s(i...j) a palindrome
//ans lies in cell dp[0][n-1] i.e. full string : s(0...n-1)

int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    int** dp = new int*[n];
	    for (int i = 0; i < n; i++)
	        dp[i] = new int[n];
	    
	    for (int i = 1; i < n; i++){
	        for (int j = 0; j < n - i; j++){
	            int si = j;
	            int ei = j + i;
	            if (s[si] == s[ei])
	                dp[si][ei] = dp[si + 1][ei - 1];
	            else{
	                int ans1 = dp[si][ei - 1] + 1;
	                int ans2 = dp[si + 1][ei] + 1;
	                dp[si][ei] = min(ans1, ans2);
	            }
	        }
	    }
	    cout<<dp[0][n - 1]<<endl;
	}
	return 0;
}
//APPROACH3: Find longest common subsequence
//between s ans reverse(s), n = length of s/s_rev
//ans = n - len(lcs of s and s_rev)
//O(n^2) time , O(n^2) space

//eg. s = aba, s_rev = aba, lcs = 3, ans = 3 - 3 = 0
//eg. s = bacea, s_rev = aecab, lcs = 3 (aea or aca)
//for aea: b a c e   a
//           a   e c a b
//2 uncommon chars: b,c to be added to get: bace'c'a'b'
//for aca: b a   c e a 
//           a e c   a b
//2 uncommon chars:b,e to be added to get: ba'e'cea'b'
//Hence, answer = n - lcs = 5 - 3 = 2


int main() {
	int t; cin>>t;
	while(t--){
	    string s_rev;
	    cin>>s_rev;
	    string s = s_rev;
	    reverse(s_rev.begin(), s_rev.end());
	    int n = s.length();
	    int** dp = new int*[n + 1];
	    for (int i = 0; i <= n; i++)
	        dp[i] = new int[n + 1];
	    
	    for (int i = 0; i <= n; i++)
	        dp[i][0] = 0;
	        
	    for(int j = 1; j <= n; j++)
	        dp[0][j] = 0;
	        
	    for(int i = 1; i <= n; i++){
	        for (int j = 1; j <= n; j++){
	            if (s[n - i] == s_rev[n - j])
	                dp[i][j] = dp[i - 1][j - 1] + 1;
	            else{
	                int ans1 = dp[i - 1][j];
	                int ans2 = dp[i][j - 1];
	                int ans3 = dp[i - 1][j - 1];
	                dp[i][j] = max(ans1, max(ans2, ans3));
	            }
	        }
	    }
	    cout<<n - dp[n][n]<<endl;
	}
	return 0;
}




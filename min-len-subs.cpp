//Given a string str consisting of lowercase 
//English letters and an integer K. The task is to find 
//the minimum length of the sub-string whose characters 
//can be used to form a palindrome of length K. 
//If no such sub-string exists then print -1.

//eg. Input: s = “abcda”, k = 2
//Output: 5 i.e abcda
//In order to form a palindrome of length 2, 
//both the occurrences of ‘a’ are required.
//Hence, the length of the required sub-string will be 5.

//eg. Input: s = “abcde”, k = 5
//Output: -1
//No palindromic string of length 5 can be 
//formed from the characters of the given string.

//eg. s = adebda
//if k = 2, ans: 4, 'debd' => dd
//if k = 3, ans: 4, 'debd' => ded or dbd
//if k = 4, ans: 6, 'adebda' => adda

//APPROACH: Binary search
//For string s,of size n and a given integer k
//for ans, min length = k, max length = n
//so , low, l = k and high, h = n 
//apply binary search on length, mid, m = (l + h)/2
//check if a substring of s of length m 
//can make a palindrome of length k,
//if yes, we save the current m in ans and
//find a lower (better) length, so l = l, h = m - 1
//if no, then we go to higher length, l = m + 1, h = h
//if everything returns false, then return ans = -1


#include<iostream>
using namespace std;
bool checkPalinbyFreq(int* freq, int k){
    int flag = 0;
    int max_l = 0;
    for (int i = 0; i < 26; i++){
        if (freq[i] == 0)
            continue;
        else if (freq[i] == 1)
            flag = 1;
        else{
            if (freq[i] % 2 == 1)
                flag = 1;
            max_l += freq[i]/2;
        }
    }
    if (k%2 == 1){
        if (2*max_l + flag >= k)
            return true;
    }
    else{
        if (2*max_l >= k)
            return true;
        }
    return false;
}
bool checkPalinOfLengthM(string s, int m, int k){
    int freq[26] = {0};
    for (int i= 0; i < m; i++)
        freq[s[i] - 'a']++;
        
    if (checkPalinbyFreq(freq, k))
        return true;
    
    for (int i = m; i < s.length(); i++){
        freq[s[i - m] - 'a']--;
        freq[s[i] - 'a']++;
        if (checkPalinbyFreq(freq, k))
            return true;
    }
    return false;
}
int findMinSubs(string s, int n, int k){
    int l = k;
    int h = n;
    
    int ans = -1;
    while (l <= h){
        int m = (l + h)/2;
        if (checkPalinOfLengthM(s, m, k)){
            ans = m;
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return ans;
}
int main()
{
	string s ="adebda";
	int k = 2; 
	int n = s.size();
	cout<<findMinSubs(s,n,k)<<endl;
	return 0;
}
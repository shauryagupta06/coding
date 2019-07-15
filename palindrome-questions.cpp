//Question1: Given a string s we need to tell minimum 
//characters to be appended (insertion at end) to 
//make a string palindrome.
//eg. s = abede, ans = 2 : abede'ba'
//Idea: keep deleting chars until a palindrome found
//basically finding longest palindromic suffix
//Answer is the no. of chars deleted
//recursive approach 

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
bool checkPalindrome(string s){
    int n = s.size();
    int i = 0; 
    int j = n - 1;
    while (i <= j){
        if (s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int minAppends(string s){
    if (checkPalindrome(s))
        return 0;
    
    return 1 + minAppends(s.substr(1));
    
}
int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<minAppends(s)<<endl;
	}
	return 0;
}

//Question2: Given a string S, determine the least 
//number of characters that should be added 
//on to the left side of S so that the complete 
//string becomes a palindrome.

//Idea: Find longest palindromic prefix, then no. of 
//insertions = n - len(lpp)
//eg. s = java, lpp = j(1) ans: 4-1 = 3: avajava
//eg. abbacd, lpp = abba(4) ans = 2 : dcabbacd

//recursive solution
bool checkPalindrome(string s){
    int n = s.size();
    int i = 0; 
    int j = n - 1;
    while (i <= j){
        if (s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int minLeftInsertions(string s){
    if (checkPalindrome(s))
        return 0;
    
    int n = s.size();
    return 1 + minLeftInsertions(s.substr(0,n - 1));
    
}
int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<minLeftInsertions(s)<<endl;
	}
	return 0;
}
//iterative solution
bool checkPalindrome(string s){
    int n = s.size();
    int i = 0; 
    int j = n - 1;
    while (i <= j){
        if (s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    int count = n;
	    for (int i = n ; i >= 1 ; i--){
	        if (checkPalindrome(s.substr(0,i))){
	            count = i;
	            break;
	        }
	    }
	    cout<<n - count<<endl;
	}
	return 0;
}
//Question3: Given a string of lowercase letters. 
//Find minimum characters to be inserted in string 
//so that it can become palindrome. 
//We can change positions of characters in string.
//eg. abcde ans: 4 : abcdedcba
//eg. aabbc ans: 0 : abcba or bacab

//Idea: Find no. of characters with odd count
//chars with even count will balance themselves
//one odd count char can stay in middle
//other odd count chars need to be added
//eg. cccdee: cecdce'c' ans : 1
//here, d is kept in between, one 'c' is added , 
//other two c's will balance themselves
//odd_c = no. of chars with odd count
//if odd_c = 0, no insertion needed, rearrange to
//form a palindrome, ans = 0
//else ans = odd_c - 1

bool checkPalindrome(string s){
    int n = s.size();
    int i = 0; 
    int j = n - 1;
    while (i <= j){
        if (s[i] == s[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int n = s.length();
	    int odd_c = 0;
	    unordered_map<char,int> cmap;
	    for (int i = 0; i < n; i++)
	        cmap[s[i]]++;
	    
	    unordered_map<char,int> :: iterator itr;
	    for (itr = cmap.begin(); itr != cmap.end(); itr++){
	        if (itr->second % 2 == 1)
	            odd_c++;
	    }
	    int ans = (odd_c == 0) ? 0 : odd_c - 1; 
	    cout<<ans<<endl;
	}
	return 0;
}





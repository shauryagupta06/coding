//every round removal (traversing entire string)
//eg. mississipie
//after 1st round: miiipie
//after 2nd round: mpie
//mpie has no dulplicate characters
//Hence, return ans = mpie

//brute force, gives TLE //exponential
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void removeDuplicates(string s, int n, string& ans){
    if (n == 0)
        return;
    if (s[0] == s[1]){
        int idx = 1;
        for (int i = 2; i < n; i++){
            if (s[i] == s[0]){
                idx = i;
            }
            else{
                break;
            }
        }
        removeDuplicates(s.substr(idx+1), n - (idx + 1), ans);
    }
    else{
        ans = ans + s[0];
        removeDuplicates(s.substr(1), n - 1, ans);
    }
    
}
bool checkDone(string s){
    for (int i = 0; i < s.size() - 1; i++){
        if (s[i] == s[i+1]){
            return false;
        }
    }
    return true;
}
void removeDupRecursive(string s, int n, string& final_ans){
    string ans = "";
    removeDuplicates(s, n, ans);
    while (checkDone(ans) == false){
        removeDuplicates(s, n, ans);
    }
    final_ans = ans;
    return;
}
int main() {
	int t; cin>>t;
	while(t--){
	    string s; 
	    cin>>s;
	    int n = s.size();
	    string final_ans = "";
	    removeDupRecursive(s, n, final_ans);
	    for (int i = 0; i < final_ans.size(); i++){
	        cout<<final_ans[i];
	    }
	    cout<<endl;
	}
	return 0;
}
//Same approach through iteration, maintaing flags
//worst case : O(n^2)
#include <iostream>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int flag;
	    do{
	        flag = 0;
	        int flagc = 1;
	        int n = s.size();
	        string q = "";
	        for (int i = 0; i < n - 1; i++){
	            if (s[i] != s[i + 1]){
	                if (flagc){
	                    q += s[i];
	                }
	                else{
	                    flagc = 1;
	                }
	            }
	            else{
	                flag = 1;
	                flagc = 0;
	            }
	        }
	        if (s[n-1] != s[n-2])
	            q += s[n-1];
	        s = q;
	    }while(flag);
	    cout<<s<<endl;
	}
	return 0;
}
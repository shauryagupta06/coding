#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define no_chars 256

//Non-Repeating Character Substring
//eg, acvdasd : ans - cvdas ,length =5
//O(n) time

string printNRCS(string s){
    int n=s.size();
    int cur_len = 1;
    int max_len = 1;
    int prev_index;
    int start = 0;
    
    int visited[no_chars];
    for (int i = 0; i < no_chars; i++) 
        visited[i] = -1; 
    visited[s[0]] = 0;
    
    for (int i=1;i<n;i++){
        prev_index = visited[s[i]];
        if (prev_index == -1 || i - cur_len > prev_index)
            cur_len++;
        else{
            if (cur_len > max_len){
                max_len = cur_len;
                start = i - cur_len;
            }
            cur_len = i - prev_index;
        }
        visited[s[i]] = i;
        //cout<<cur_len<<" ";
    }
    if (cur_len > max_len)
        max_len = cur_len;
        
    return s.substr(start,max_len);
}
int main() {
	int t;cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<printNRCS(s)<<endl;
	}
	return 0;
}
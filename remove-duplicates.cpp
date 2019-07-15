//O(n^2) complexity
//O(1) auxilliary space

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
string removeDuplicates(string& s){
    int i,j,index;
    index=0;
    int count=0;
    string ans;
    for (i=0;i<s.size();i++){
        for(j=0;j<=i-1;j++){
            if(s[i] == s[j])
                break;
            
        }
        if (i == j)
            s[index++] = s[i];
    }
    
  
    return s.substr(0,index);
}
int main() {
    int t;cin>>t;
	cin.ignore();
	while(t--){
	    string s;
	    getline(cin,s);
	    cout<<removeDuplicates(s)<<endl;
	    //cout<<s<<endl;
	}
}
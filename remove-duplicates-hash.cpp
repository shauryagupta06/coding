#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define no_chars 256
string removeDuplicates(string& s){
    bool bin_hash[no_chars] = {false};
    int index = 0;
    for (int i=0;i<s.size();i++){
        if (bin_hash[s[i]]==false){
            s[index++] = s[i];
            bin_hash[s[i]]=true;
        }
    }
    return s.substr(0,index) ;
}
int main() {
    int t;cin>>t;
	cin.ignore();
	while(t--){
	    string s;
	    getline(cin,s);
	    //removeDuplicates(s);
	    cout<<removeDuplicates(s)<<endl;
	    //cout<<s<<endl;
	}
}
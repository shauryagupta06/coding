#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool checkAnagram(string str1,string str2){
    if (str1.length() != str2.length())
        return false;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    
    for (int i=0;i<str1.size();i++){
        if (str1[i] != str2[i]){
            return false;
            break;
        }
    }
    return true;
}
int main() {
	int t;cin>>t;
	while(t--){
	    string str1,str2;
	    cin>>str1>>str2;
	    if (checkAnagram(str1,str2))
	        cout<<"YES"<<endl;
	    else 
	        cout<<"NO"<<endl;
	}
	return 0;
}
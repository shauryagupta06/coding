#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool checkAnagram(string str1,string str2){
    if (str1.length() != str2.length())
        return false;
    
    int count[26] = {0};

    
    for (int i=0;i<str1.size();i++){
        count[str1[i]-'a']++;
        count[str2[i]-'a']--;
    }
    for (int i=0;i<26;i++){
        if (count[i] != 0){
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
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool checkAnagram(string str1,string str2){
    if (str1.length() != str2.length())
        return false;
    
    int value = 0;

    
    for (int i=0;i<str1.size();i++){
        value = value ^ (int)str1[i];
        value = value ^ (int)str1[i];
    }
   
    return value == 0;
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
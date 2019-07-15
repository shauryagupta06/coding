#include <iostream>
using namespace std;
#include <bits/stdc++.h>
bool checkAnagram(string str1,string str2){
    if (str1.length() != str2.length())
        return false;
    
    int count1[256] = {0};
    int count2[256] = {0};
    
    for (int i=0;i<str1.size();i++){
        count1[str1[i]]++;
        count2[str2[i]]++;
    }
    for (int i=0;i<256;i++){
        if (count1[i] != count2[i]){
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
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

//input : april ape apple
//arr_sorted : ape apple april
//check only ape and april
//ans : ap
string commonPrefTwo(string str1,string str2){
    int min_len = (str1.size()<str2.size())?str1.size():str2.size();
    int cp=0;
    for (int i=0;i<min_len;i++){
        if (str1[i] == str2[i])
            cp++;
        else
            break;
    }
    return str1.substr(0,cp);
}
string commonPrefix(string arr[], int n){
    sort(arr,arr+n);
    return commonPrefTwo(arr[0],arr[n-1]);
}
int main() {
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;

	    string arr[n];
	  
	    for (int i=0;i<n;i++){
	        cin>>arr[i];
	    }
        string ans = commonPrefix(arr,n);
        if (ans=="")
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
	 
	}
	return 0;
}
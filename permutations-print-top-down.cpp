#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void printPermutations(string input,string output){
    if (input.size()==0){
        cout<<output<<" ";
        return;
    }

    for (int i=0;i< input.size();i++){
        printPermutations(input.substr(0,i)+input.substr(i+1),output+input.substr(i,1));
    }
    return;
  }
int main() {
	int t;cin>>t;
	while (t--){
	    string input;
	    cin>>input;
	    int n= input.size();
        sort(input.begin(),input.end());
        string output;
	    printPermutations(input,output);
	    
	    cout<<endl;
	}
	return 0;
}
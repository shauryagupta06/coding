#include <iostream>
using namespace std;
#include <bits/stdc++.h>
void printPermutations(string input,int l, int r){
    if (l==r){
        cout << input<<" ";
        return;
    }
    sort(input.begin()+l,input.end());
    for (int i=l;i<=r;i++){
        swap(input[l],input[i]);
        printPermutations(input,l+1,r);
        swap(input[l],input[i]);
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
	    printPermutations(input,0,n-1);
	    
	    cout<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int returnPermutations(string input,string output[]){
 
  if (input.size()==0){
  output[0]="";
  return 1;
  }
  int i,j,osize;
  string o[10000];
  
  osize= returnPermutations(input.substr(1),o);
  int k=0;
  for (i=0;i<osize;i++){
      for (j=0;j<=o[i].size();j++){
        output[k++]= o[i].substr(0,j) + input[0] + o[i].substr(j);
        }
      } 
  return k;
  }
int main() {
	int t;cin>>t;
	while (t--){
	    string input;
	    cin>>input;
	    string output[120];
	    int no_of_permutations = returnPermutations(input,output);
	    sort(output,output+no_of_permutations);
	    for (int i=0;i<no_of_permutations;i++){
	        cout<<output[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
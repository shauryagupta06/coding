#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int returnPermutations(string input,string output[]){
 
  if (input.size()==0){
  output[0]="";
  return 1;
  }
  int i,j,smallOutputsize;
  string o[1000];
  for (i=0;i<input.size();i++){
   smallOutputsize= returnPermutations(input.substr(0,i)+input.substr(i+1),o);
      for (j=0;j<smallOutputsize;j++){
        output[j+(i*smallOutputsize)]= input.substr(i,1)+o[j];
        }
      } 
  return input.size()*smallOutputsize;
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
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
    int t;cin>>t;
	while (t--){
	    int r,c;
	    cin>>r>>c;
	    int* rows = new int[r];
	    int* cols = new int[c];
	    for (int i=0;i<r;i++)
	        rows[i] = 0;
	    for (int i=0;i<c;i++)
	        cols[i] = 0;
	    for (int i=0;i<r;i++){
	        for (int j=0;j<c;j++){
	            int a;
	            cin>>a;

	            if (a == 1){
	                rows[i] = 1;
	                cols[j] = 1;
	            }
	        }
	    }
	    
	    for (int i=0;i<r;i++){
	        for (int j=0;j<c;j++){
	            
	            if (rows[i] == 1 || cols[j] == 1)
	                cout<<1<<" ";
	            else 
	                cout<<0<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
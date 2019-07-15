#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;

	    string arr[n];
	  
	    for (int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    
	    if (n==1)
	        cout<<arr[0]<<endl;
	    else{
	    int min_size = arr[0].size();
	    for (int i = 1;i<n;i++){
	        if (arr[i].size()< min_size)
	            min_size = arr[i].size();
	    }
	    int lp = 0;
	    int i = 0;
	    while (i<min_size){
	        for (int j=1;j<n;j++){
	            if (arr[j-1][i] != arr[j][i])
	                break;
	            if (j == n-1)
	                lp++;
	        }
	        i++;
	    }
	    if (lp == 0)
	        cout<<-1<<endl;
	    else
	        cout<<arr[0].substr(0,lp)<<endl;
	    }
	}
	return 0;
}
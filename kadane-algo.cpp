#include <iostream>
using namespace std;
//find largst sum of subarray
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int* a = new int[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int cMax=a[0];
	    int gMax=a[0];
	    for(int i=1;i<n;i++){
	        cMax = max(a[i],cMax+a[i]);
	        gMax = max(cMax,gMax);
	    }
	    cout<<gMax<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
#define ll unsigned long long int
int main() {
	int t;cin>>t;
	while(t--){
	    ll n;cin>>n;
	    ll *a = new ll[n];
	    for(ll i=0;i<n;i++)
	        cin>>a[i];
	        
	    ll imin = 0;
	    ll imax = n-1;
	    ll large = a[imax]+1;
	    
	    for (ll i=0;i<n;i++){
	        if (i%2==0){
	            a[i] += (a[imax]%large) * large;
	            imax--;
	        }
	        else {
	            a[i] += (a[imin]%large) * large;
	            imin++;
	        }
	    }
	    for (ll i=0;i<n;i++){
	        a[i] = a[i]/large;
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
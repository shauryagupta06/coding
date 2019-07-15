#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
#define ll unsigned long long int
int main() {
	int t;cin>>t;
	while(t--){
	    ll nx,ny;
	    cin>>nx>>ny;
	    ll *ax = new ll[nx];
	    ll *ay = new ll[ny];
	    for (ll i=0;i<nx;i++){
	        cin>>ax[i];
	    }
	    for (ll i=0;i<ny;i++){
	        cin>>ay[i];
	    }
	    sort(ay,ay+ny);
	    sort(ax,ax+nx);
	    
	    ll count = 0;
	    ll j=0;
	    while (ax[j]<1 && j<nx)
	        j++;
	    ll x1 = j;
	    while (ax[j]<2 && j<nx)
	        j++;
	    ll x2 = j;
	    while (ax[j]<3 && j<nx)
	        j++;
	    ll x3 = j;
	    while (ax[j]<4 && j<nx)
	        j++;
	    ll x4 = j;
	    j=0;
	    while (ay[j]<1 && j<ny)
	        j++;
	    ll y1 = j;
	    while (ay[j]<2 && j<ny)
	        j++;
	    ll y2 = j;
	    while (ay[j]<3 && j<ny)
	        j++;
	    ll y3 = j;
	    while (ay[j]<5 && j<ny)
	        j++;
	    ll y5 = j;
	    //count will increase by no. of zeros in y for each 1 in x
	    count += (x2-x1)*y1;
	    
	    //count will inc. for each 2 in x, for nos. 5 and above in y
	    count += (x3-x2)*(ny-y5);
	    
	    //count will inc. for each 3 in x, no. of 2s in y
	    count += (x4 - x3)*(y3 - y2);
	    
	    //count will inc for y=0, for all x 2 and above
	    count += y1*(nx - x2);
	    
	    //count will inc for y=1, for all x 2 and above
	    count += (y2-y1)*(nx - x2);
	    
	    
	    ll k=x3;
	    ll l=0;
	    while (k < nx){
	            while (ay[l] <= ax[k])
	                l++;
	            if (l < ny)
	                count += (ny - l);
	            else 
	                break;
	        k++;
	    }
	   
	    
	   
	    cout<<count<<endl;
	}
	return 0;
}
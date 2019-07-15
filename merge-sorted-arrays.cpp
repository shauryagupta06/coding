#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define ll unsigned long long int
ll nextGap(ll gap){
    if (gap<=1)
        return 0;
    return (gap/2) + (gap%2);
}
int shellSort(ll x[], ll nx, ll y[], ll ny){

    ll i,j;
    ll gap = nx + ny;
    for (gap = nextGap(gap); gap >0; gap = nextGap(gap)){
        
        for (i = 0; i+gap < nx; i++){
            if (x[i] > x[i+gap])
                swap(x[i],x[i+gap]);
        }
        
        for (j = gap > nx?gap - nx:0; j<ny && i<nx; j++, i++){
            if (x[i] > y[j])
                swap(x[i], y[j]);
        }
        
        if (j < ny){
            for (j = 0; j + gap < ny; j++){
                if (y[j] > y[j+gap])
                    swap(y[j], y[j+gap]);
            }
        }
        
    }
    return 0;
}
int main() {
    int t;cin>>t;
    while(t--){
        ll nx, ny;
        cin>>nx>>ny;
        ll *x = new ll[nx];
        ll *y = new ll[ny];
        for (ll i=0;i<nx;i++)
	        cin>>x[i];
	    for (ll i=0;i<ny;i++)
	        cin>>y[i];
	    

	    shellSort(x,nx,y,ny);
	    
	    for (ll i=0;i<nx;i++)
	        cout<<x[i]<<" ";

	    for (ll i=0;i<ny;i++)
	        cout<<y[i]<<" ";
	   cout<<endl;
    }

	return 0;
}
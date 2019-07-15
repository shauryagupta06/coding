#include <iostream>
using namespace std;
#define ll unsigned long long int
ll merge(ll a[], ll l, ll m, ll r){
    ll i_count = 0;
    ll i,j,k;
    ll n1 = m-l+1;
    ll n2= r-m;
    ll L1[n1],L2[n2];
    for (i=0;i<n1;i++){
        L1[i] = a[l+i];
    }
    for (j=0;j<n2;j++){
        L2[j] = a[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while (i<n1 && j<n2){
        if (L1[i] <= L2[j]){
            a[k] = L1[i];
            k++;
            i++;
        }
        else {
            a[k] = L2[j];
            i_count += (n1-i);
            k++;
            j++;
        }
    }
    
    while (i < n1){
        a[k] = L1[i];
        i++;
        k++;
    }
     while (j < n2){
        a[k] = L2[j];
        j++;
        k++;
    }
    return i_count;
}
ll mergeSort(ll a[],ll l,ll r){
 ll i_count = 0;
if (l<r){
 
   ll m=l+(r-l)/2;
   
   i_count = mergeSort(a,l,m);
   i_count += mergeSort(a,m+1,r);
   
   i_count += merge(a,l,m,r);
}
return i_count;
}
int main() {
	
	int t;cin>>t;
	while(t--){
	    ll n;cin>>n;
	    ll* a = new ll[n];
	    for (ll i=0;i<n;i++){
	        cin>>a[i];
	    }
	    ll ans = mergeSort(a,0,n-1);
	    cout<<ans<<endl;
	}
}
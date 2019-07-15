#include <iostream>
using namespace std;
#include <algorithm>
#include<climits> 
#include <cstdlib>

//Quick select method 

void swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int a[], int l,int r){
     // Random quick sort
    srand(time(NULL)); 
    int random = l + rand() % (r - l + 1); 
    swap(&a[random], &a[r]); 
    //same as normal quick sort with last element as pivot
    //Lomuto method used here
    int pi = a[r];
    int i = l;
    for (int j = l;j<r;j++){
        if (a[j] <= pi){
            swap(&a[i],&a[j]);
            i++;
        }
    }
    swap(&a[r],&a[i]);
    return i;
}
int kthSmallest(int a[], int l, int r, int k) 
{ 
    if (k>0 && k<=(r-l)+1){
        int pi = partition(a,l,r);
        if (pi-l == k-1)
            return a[pi];
        else if (pi-l > k-1 )
            return kthSmallest(a,l,pi-1,k);
        else
            return kthSmallest(a,pi+1,r,k-(pi-l+1));
    }
    return INT_MAX;
} 
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int *a = new int[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int k;
	    cin>>k;
	    cout<<kthSmallest(a,0,n-1,k)<<endl;
    }
	return 0;
}
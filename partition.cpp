#include <iostream>
using namespace std;
//google dutch national flag problem
void swap(int& a,int& b){
    int temp;
    temp = a;
    a = b;
    b = temp; 
}
int main() {
	int t;cin>>t;

	while(t--){
	    int n;cin>>n;
	    int* a = new int[n];
	    for (int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    int mid = 1;
	    int i=0;
	    int j=0;
	    int k=n-1;
	    while (j<=k){
	        if (a[j]<mid){
	            swap(a[j],a[i]);
	            i++;
	            j++;
	        }
	        else if(a[j]>mid){
	             swap(a[j],a[k]); 
	            k--;
	        }
	        else{
	            j++;
	        }
	        
	    }
	    for (int l=0;l<n;l++){
	        cout<<a[l]<<" ";
	    }
	   cout<<endl; 
	}
	return 0;
}
#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int r){
    int i,j,k;
    int n1 = m-l+1;
    int n2= r-m;
    int L1[n1],L2[n2];
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
}
void mergeSort(int a[],int l,int r){

if (l<r){
 
   int m=l+(r-l)/2;
   
   mergeSort(a,l,m);
   mergeSort(a,m+1,r);
   
   merge(a,l,m,r);
}
}
int main() {
	
	int a[] = {2,3,7,1,8};
	for (int i=0;i<5;i++)
	cout<<a[i]<<" ";
	mergeSort(a,0,4);
	for (int i=0;i<5;i++)
	cout<<a[i]<<" ";
	return 0;
}
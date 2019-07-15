#include <iostream>
using namespace std;
#include <climits>
void swap(int *x, int *y){
        int temp;
        temp = *x;
        *x = *y;
        *y = temp;
    }

class MinHeap{
    int *harr;
    int capacity;
    int heap_size;
    
    public:
    MinHeap(int a[], int n){
        heap_size = n;
        harr = a;
        int i= (heap_size-1)/2;
        while(i>=0){
            MinHeapify(i);
            i--;
        }
    }
   
    void MinHeapify(int i){
        int l = leftc(i);
        int r = rightc(i);
        int smallest = i;
        if ((l<heap_size) && harr[l]<harr[i])
            smallest = l;
        if ((r<heap_size) && harr[r]< harr[smallest])
            smallest = r;
        if (smallest != i){
            swap (&harr[i],&harr[smallest]);
            MinHeapify(smallest);
        }
    }
    int parent(int i){
        return (i-1)/2;
    }
    int leftc(int i){
        return (2*i + 1);
    }
    int rightc(int i){
        return (2*i + 2);
    }
    int extractMin(){
        if (heap_size==0)
            return INT_MAX;
        
        int root = harr[0];
        if (heap_size > 1){
            harr[0] = harr[heap_size - 1];
            MinHeapify(0);
        }
        heap_size--;
        return root;
    }
    int getMin(){
        return (harr[0]);
    }
};
int kthsmallest (int a[], int n, int k){
    MinHeap mh(a,n);
    
    for(int i=0;i<k-1;i++)
        mh.extractMin();
        
    return mh.getMin();
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
	    cout<<kthsmallest(a,n,k)<<endl;
    }
	return 0;
}
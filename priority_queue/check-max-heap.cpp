//given array, return true if max heap

//APPROACH: check for every parent (from 0 to (n/2) - 1) index
//it has to largest among its existing children

//O(logn) time

bool checkMaxHeap(int arr[], int n){
    for (int i = 0; i < n/2; i++){
        int parent = i;
        int leftChild = 2*parent + 1;
        int rightChild = 2*parent + 1;
        int lar = parent;
        if (arr[leftChild] > arr[lar])
            lar = leftChild;
        if (rightChild < n && arr[rightChild] > arr[lar])
            lar = rightChild;
        if (lar == parent){
            continue;
        }
        else{
            return false;
        }
    }
}

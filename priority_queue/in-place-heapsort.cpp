//O(nlogn) time O(1) space
void inplaceHeapSort(int input[], int n){
    
    for (int i = 1; i < n; i++){
        
        int childIndex = i;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(input[childIndex] < input[parentIndex]) {
                int temp = input[childIndex];
                input[childIndex] = input[parentIndex];
                input[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
    }
    
    int size = n;
    while (size > 1){
        int temp = input[0];
        input[0] = input[size - 1];
        input[size - 1] = temp;
        size --;
        
        int parent = 0;
        int leftChild = 2*parent + 1;
        int rightChild = 2*parent + 2;
        
        while (leftChild < size){
            int smallest = parent;
            if (input[leftChild] < input[smallest])
                smallest = leftChild;
            if (rightChild < size && input[rightChild] < input[smallest])
                smallest = rightChild;
            if (smallest == parent)
                break;
            int temp = input[parent];
            input[parent] = input[smallest];
            input[smallest] = temp;
            
            parent = smallest;
            leftChild = 2*parent + 1;
            rightChild =  2*parent + 2;
        }
    }
}

#include <vector>
//All operations O(logn) time
/*******************
 * Main function -
*
int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMin
                cout << pq.removeMin() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
**************************/


class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
        if (isEmpty()){
            return INT_MIN;
        }
        int n = pq.size();
        int ans = pq[0];
        pq[0] = pq[n - 1];
        pq.pop_back();
        
        int size = pq.size();
        int parent = 0;
        int leftChild = 2*parent + 1;
        int rightChild = 2*parent + 2;
        
        while (leftChild < size){
            int smallest = parent;
            if (pq[leftChild] < pq[smallest])
                smallest = leftChild;
            if (rightChild < size && pq[rightChild] < pq[smallest])
                smallest = rightChild;
            if (smallest == parent)
                break;
            int temp = pq[parent];
            pq[parent] = pq[smallest];
            pq[smallest] = temp;
            
            parent = smallest;
            leftChild = 2*parent + 1;
            rightChild =  2*parent + 2;
        }
        return ans;
    }
    
    
    
};

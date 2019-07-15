#include<vector>
#include<climits>
//All operations O(logn) time
/***************
 * Following is the main function that er are using internally
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
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
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
*******************/

class PriorityQueue {
    vector<int> pq;
    public: 
    PriorityQueue(){
        
    }
    int getSize(){
        return pq.size();
    }
    bool isEmpty(){
        return (pq.size() == 0);
    }
    int getMax(){
        if (isEmpty())
            return INT_MIN;
        return pq[0];
    }
    void insert(int ele){
        pq.push_back(ele);
        int child = pq.size() - 1;
        int parent = (child - 1)/2;
        while (child > 0){
            if (pq[child] > pq[parent]){
                int temp = pq[child];
                pq[child] = pq[parent];
                pq[parent] = temp;
            }
            else {
                break;
            }
            child = parent;
            parent = (child - 1)/2;
        }
    }
    int removeMax(){
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
            int largest = parent;
            if (pq[leftChild] > pq[largest])
                largest = leftChild;
            if (rightChild < size && pq[rightChild] > pq[largest])
                largest = rightChild;
            if (largest == parent)
                break;
            int temp = pq[parent];
            pq[parent] = pq[largest];
            pq[largest] = temp;
            
            parent = largest;
            leftChild = 2*parent + 1;
            rightChild =  2*parent + 2;
        }
        return ans;
    }
    
    
    
    
};

//Given a stream of n integers. For every ith integer, 
//add it to the running list of integers and print the 
//resulting median (of the list till now).
//Print the only integer part of median.

//6
//6 2 1 3 7 5
//Solution: 
/* S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4*/

//APPROACH1: Insertion Sort
//Add 1 element, find its correct position, return median
//O(n^2) time
//Space : O(1) , original array will change
//If original array should not be changed,
//O(n) space required 

#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void findMedian(int arr[], int n){
    cout<<arr[0]<<endl;
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int k = i - 1;
        while (k >= 0 && arr[k] > temp){
            arr[k + 1] = arr[k];
            k --;
        }
        arr[k + 1] = temp;
        if (i % 2 == 0){
            cout<<arr[i/2]<<endl;
        }
        else{
            int ans = arr[i/2] + arr[(i + 1)/ 2];
            cout << ans/2 << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    return 0;
}

//APPROACH2: Maintain two heaps: one min and one max
//If new element is less than max heap top, 
//insert it in max heap , else insert in min heap
//Their size difference should not exceed 1 at any stage
//After correcting size difference, if the sizes are equal,
//even elements, print average of top of both heaps
//If size difference is 1, odd elements
//print top of heap which has greater size

//Time : O(nlogn) Space: O(n)

#include<iostream>
#include<queue>
void findMedian(int arr[], int n){
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    
    max_pq.push(arr[0]);
    cout<<max_pq.top()<<endl;
    
    for (int i = 1; i < n ; i++){
        if (arr[i] < max_pq.top()){
            max_pq.push(arr[i]);
        }
        else{
            min_pq.push(arr[i]);
        }
        
        if (abs(max_pq.size() - min_pq.size()) > 1){
            int s = max(max_pq.size(), min_pq.size());
            if (s == max_pq.size()){
                int t = max_pq.top();
                min_pq.push(t);
                max_pq.pop();
            }
            else if (s == min_pq.size()){
                int t = min_pq.top();
                max_pq.push(t);
                min_pq.pop();
            }
        }
        
        if (max_pq.size() == min_pq.size()){
            int ans = (max_pq.top() + min_pq.top())/2;
            cout<<ans<<endl;
        }
        else{
            int s = max(max_pq.size(), min_pq.size());
            if (s == max_pq.size()){
                cout<<max_pq.top()<<endl;
            }
            else if (s == min_pq.size()){
                cout<<min_pq.top()<<endl;
            }
        }
    }
    return;

}

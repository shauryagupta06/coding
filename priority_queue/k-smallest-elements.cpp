//You are given with an integer k and an array of integers
//that contain numbers in random order. Write a program to
//find k smallest numbers from given array.
//You need to save them in an array and return it.

//eg. n =13
//    a = [2 12 9 16 10 5 3 20 25 11 1 8 6] 
//    k = 4
//ans: 5 3 2 1

//APPROACH: max priority queue of size k
//push first k elements of array in pq
//for each element after that, check 
//if array element is smaller than largest element of pq
//yes means new element has a place in ans 
//so add it, and remove the largest element
//till ith index,pq stores k smallest elements of array(0..i)

//Time complexity O(nlogk) because size of priority queue
//is max k at a time
//space complexity is O(k).

#include<queue>
vector<int> kSmallest(int *input, int n, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++){
        pq.push(input[i]);
    }
    for (int i = k; i < n; i++){
        if (input[i] < pq.top()){
            pq.pop();
            pq.push(input[i]);
        }
        else {
            continue;
        }
    }
    vector<int> ans;
    while (!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
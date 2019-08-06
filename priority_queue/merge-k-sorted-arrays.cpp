//Given k different arrays(diff sizes), 
//which are sorted individually (ascending)
//output array should be sorted (in ascending order).

//APPROACH: A min priority queue pq, 
//initially holds k elements : first ele of each array
//info is a data type such that;
//info.first = element
//info.second.first = array index to which element belongs
//info.second.second = element index within array
//pq based on element, picks min, inserts it to ans vector
//if next element present in array, add it to pq
//else do nothing(size of pq will decrease)
//when all arrays exhausted, pq becomes empty

//max size of pq = k, each operation = logk
//loop N times, N = total elements in all k arrays
//Time : O(N*logk), if all k arrays of n size - Time O(nk*logk)
//Space: O(N) 

//Note: we are given a vector of vector pointers
//if v is a vector pointer
//to access array elements, (*v).at(i) ~ v->at(i) or (*v)[i]
//for functions: v->size()
//we can also create a reference, vector<int> &vr = *v;
//treat vr as normal vector, eg. vr[i]

#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    int k = input.size();
    vector<int> ans;
    typedef pair<int, pair<int, int>> info;
    priority_queue<info, vector<info>, greater<info>> pq;
    for (int i = 0; i < k; i++){
        info info1;
        info1.first = input[i]->at(0);
        info1.second.first = i;
        info1.second.second = 0;
        pq.push(info1);
    }
    
    while (pq.size() > 0){
        info prev;
        prev = pq.top();
        ans.push_back(prev.first);
        pq.pop();
        if (prev.second.second + 1 < input[prev.second.first]->size()){
            info curr;
            curr.first = (*input[prev.second.first])[prev.second.second + 1];
            curr.second.first = prev.second.first;
            curr.second.second = prev.second.second + 1;
            pq.push(curr);
        }
    }
   
    return ans;

}


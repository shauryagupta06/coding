//A queue is maintained for buying the tickets and 
//every person has attached with a priority 
//(an integer, 1 being the lowest priority). 
//The tickets are sold in the following manner -
//1. The first person (pi) in the queue asked to comes out.
//2. If there is another person present in the 
//queue who has higher priority than pi,
//then ask pi to move at end of the queue without 
//giving him the ticket.
//3.Otherwise, give him ticket (he'll not stand in queue again).
//Giving a ticket to a person takes exactly 1 minutes 
//it takes no time for removing and 
//adding a person to the queue. 
//And you can assume that no new person joins the queue.
//Given a list of priorities of N persons standing 
//in the queue and the index of your priority (i)
//(indexing starts from 0). 
//Find and return the time for i to get the ticket.

//eg. 5
//2 3 2 2 4
//i = 3
//ans: 4 
//explanation: 2 3 2 2' 4 -> 3 2 2' 4 2 -> 2 2' 4 2 3
// -> 2' 4 2 3 2 -> 4 2 3 2 2' (T = 1) -> 2 3 2 2'
// -> 3 2 2' 2 (T = 2) -> 2 2' 2 (T = 3) -> 2' 2( T = 4)
//(i got the ticket : stop and return T)

//APPROACH: Maintain a queue q of indices
//and a max priority queue of priorities
//check if curr q[i] has max priority
//yes: remove from q and pq, pq will rearrange, Increase T
//no: remove from q and push to q at back

//Worst case: T = 1 + 2+.. +n = O(n^2)
//pq will take max O(logn) time 
//Space: O(n) for q and pq

#include<queue> 
int buyTicket (int *arr, int n, int k){
    queue<int> q;
    priority_queue<int> pq;
    for (int i = 0; i < n; i ++){
        q.push(i);
        pq.push(arr[i]);
    }
    int t = 0;
    while(1){
        if (arr[q.front()] == pq.top()){
            t ++;
            if (q.front() == k){
                break;
            }
            q.pop();
            pq.pop();
        }
        else{
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    return t;
}
#include <vector>
#include<iostream>
using namespace std;

int main(){
    int n, k, s;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> k;
    cout << buyTicket(arr, n, k) << endl;
}



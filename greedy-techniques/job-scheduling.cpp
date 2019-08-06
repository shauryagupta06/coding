/*You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no 
two jobs in the subset overlap. */

//APPROACH: Greedy + Dynamic Programming
//sort the array arr of job by increasing finish time(greedy)
//maintain a dp array which will have value of max profit
//i.e. our ans till ith job(after sorting)
//dp[0] will have profit of 0th job 
//for each i, we calculate a profit excluding i
//i.e. profit till i - 1 = dp[i - 1]
//we calc profit including i, which is curr profit +
//profit of latest job which can be done if ith job
//is included
//we will fetch the index of latest job and add it to the
//including part 
//dp[i] will contain max of including and excluding

//O(n^2) solution, gives TLE 
#include <iostream>
#define ll long long
#include<bits/stdc++.h>
using namespace std;
struct job{
    ll start;
    ll finish;
    ll profit;
    job(ll s, ll f, ll p){
        start = s;
        finish = f ;
        profit = p ;
    }
    job(){}
};
bool compare(job a, job b){
    return a.finish < b.finish;
}

int main(){
    ll n; cin >> n;
    job arr[n];
    ll dp[n];
    for (ll i = 0; i < n; i++){
        ll s, f, p;
        cin >> s >> f >> p;
        job j(s, f, p);
        arr[i] = j;
        dp[i] = 0;
    }
    sort (arr, arr+n, compare);
    dp[0] = arr[0].profit;
    for (ll i = 1; i < n ; i ++){
        ll including = arr[i].profit;
        ll idx = -1;
        for (ll j = i - 1; j >= 0; j--){
            if (arr[j].finish <= arr[i].start){
                idx = j;
                break;
            }
        }
        if (idx != -1){
            including += dp[idx];
        }
        dp[i] = max(including, dp[i - 1]);
    }
    cout << dp[n - 1] << endl;
    return 0;
}

//O(n*logn) solution using binary search
//In binary search, if the condition is not true, we
//should try lowering the finish index, so we will search in
//lower bracket
//else, we save the current ans, and try accomodating
//more activities, to get the best ans, so search in 
//higher bracket
using namespace std;
struct job{
    ll start;
    ll finish;
    ll profit;
    job(ll s, ll f, ll p){
        start = s;
        finish = f ;
        profit = p ;
    }
    job(){}
};
bool compare(job a, job b){
    return a.finish < b.finish;
}
ll binarySearch(job* arr, ll i){
    ll l = 0  ;
    ll h = i - 1;
    ll ans = -1;
    while (l <= h){
        ll mid = (l + h)/2;
        if (arr[mid].finish <= arr[i].start){
            ans = mid;
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return ans;
}
int main(){
    ll n; cin >> n;
    job arr[n];
    ll dp[n];
    for (ll i = 0; i < n; i++){
        ll s, f, p;
        cin >> s >> f >> p;
        job j(s, f, p);
        arr[i] = j;
        dp[i] = 0;
    }
    sort (arr, arr+n, compare);
    dp[0] = arr[0].profit;
    for (ll i = 1; i < n ; i ++){
        ll including = arr[i].profit;
        ll idx = binarySearch(arr, i);
        if (idx != -1){
            including += dp[idx];
        }
        dp[i] = max(including, dp[i - 1]);
    }
    cout << dp[n - 1] << endl;
    return 0;
}
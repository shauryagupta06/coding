//Shaky has N (1<=N<=50000) candy boxes each of them 
//contains a non-zero number of candies (between 1 and 
//1000000000). Shaky want to distibute these candies 
//among his K (1<=K<=1000000000) students. He want to 
//distibute them in a way such that:
//1. All students get equal number of candies.
//2. All the candies which a student get
// must be from a single box only.

//eg. 9 3 2 3 , k = 2
//ans: 4
//we can give both students from 0yh box 4-4 candies

//APPROACH: Binary Search 
//min = 0(suppose there are 4 boxes with one candy each
//and 6 students, we can't give any candy, so ans = 0)
//max = highest no. of candies in any of the boxes = max(arr)
//Search between min and max, check if for given array,
//mid no. of candies can be distributed to k students
//if yes,store curr mid in ans take search to higher bracket
//if no, take search to lower bracket
//O(nlog(max)) n for check function and log(max) 
//for checking the range 

//check function: for each arr element ,divide ele by mid to
//find how many students that ele can satisfy,add it to count
//Once count reaches(or becomes greater) than k, return true

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool check(ll* arr, ll n, ll mid, ll k){
    ll count = 0;
    for (ll i = 0; i < n; i++){
        count += (arr[i]/mid);
        if (count >= k){
            return true;
        }
    }
    return false;
}
ll maxCandies(ll* arr, ll n, ll k){
    ll l = 0;
    ll h = arr[0];
    ll ans = -1;
    while (l <= h){
        ll mid = (l + h)/2;
        if (check(arr, n, mid, k)){
            ans = mid;
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t --){
        ll n, k;
        cin>>n>>k;
        ll* arr = new ll[n];
        for (ll i = 0; i < n; i++){
            cin>>arr[i];
        }
        ll a[] = { 7, 6, 5, 4, 2};
        sort(arr, arr + n, greater<ll>());
        cout<<maxCandies(arr, n, k)<<endl;
        //cout<<check(arr, n, 6, k);
    }
}

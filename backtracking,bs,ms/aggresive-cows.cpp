//Farmer John has built a new long barn, with N 
//(2 <= N <= 100,000) stalls. The stalls are located 
//along a straight line at positions x1,...,xN 
//(0 <= xi <= 1,000,000,000).
//His C (2 <= C <= N) cows don't like this barn 
//layout and become aggressive towards each other 
//once put into a stall. To prevent the cows from 
//hurting each other, FJ wants to assign the cows 
//to the stalls, such that the minimum distance 
//between any two of them is as large as possible. 
//What is the largest minimum distance?

//eg. c = 3
//positions = 1 2 8 4 9
//ans: 3
//FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
//resulting in a minimum distance of 3.

//APPROACH: Binary Search 
//min = 0(suppose there are 4 stalls and 5 cows, we can't
//adjust them in any way, so ans = 0)
//max = highest distance = max(arr) - min(arr)
//Search between min and max, check if for given array,
//mid distance can be maintained for c cows
//if yes,store curr mid in ans take search to higher bracket
//if no, take search to lower bracket
//O(nlog(max)) n for check function and log(max) 
//for checking the range 

//check function: initially cow 1 stands at 1st stall
//so, count = 1, prev = arr[0], for each arr element ,
//check if dist of prev from curr is >= mid, if yes
//increase count by 1 and update prev to curr element
//Once count reaches k, return true, else false

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool check(ll* pos, int n, int c, ll m){
    int count = 1;
    ll prev = pos[0];
    for (int i = 1; i < n; i++){
        if ((pos[i] - prev) >= m){
            count++;
            prev = pos[i];
        }
        if (count == c){
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin>>t;
    while (t --){
        int n, c;
        cin >> n >> c;
        ll* pos = new ll[n];
        for (int i = 0; i < n; i++){
            cin >> pos[i];
        }
        sort(pos, pos + n);
        ll l = 0;
        ll h = pos[n - 1] - pos[0];
        ll ans = -1;
        while (l <= h){
            ll m = (l + h) / 2;
            if (check(pos, n, c, m)){
                ans = m;
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
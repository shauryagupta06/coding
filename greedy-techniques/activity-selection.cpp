/* You are given n activities with their start and finish 
times. Select the maximum number of activities that can be 
performed by a single person, assuming that a person can only 
work on a single activity at a time. */

//APPROACH: Greedy, I will select those activities first 
//which have lesser finishing time so that I can include
//more and more activities
//Arrange activity array act in descending order of
//finishing time (pair.second)
//i = activity no. going on right now
//j = next activity to be checked
//cnt = no. of activities 
//if f time of ith activity is less than s time of jth 
//activity, current act i will become j, j will move
//one step forward and cnt will increase
//else we will skip jth activity and increment j by 1

#include<bits/stdc++.h>
using namespace std;
#define ppi pair<int, int>
bool myComparator(ppi a, ppi b){
    return (a.second < b.second);
}
int main()
{
    int n; cin >> n;
    ppi* act = new ppi[n];
    for (int i = 0; i < n; i++){
        cin >> act[i].first >> act[i].second ;
    }
    sort(act, act + n, myComparator);
    int cnt = 1;
    int i = 0;
    int j = 1;
    while (i < n - 1 && j < n){
        if (act[i].second <= act[j].first){
            cnt ++;
            i = j;
            j ++;
        }
        else{
            j++;
        }
    }
    cout << cnt << endl;
    return 0;
}
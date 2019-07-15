//recursion-brute force -exponential time 
#include <bits/stdc++.h>
int countStepsTo1_1(int n){
    if (n==1)
        return 0;
    int x,y,z;
    y = INT_MAX;
    z = INT_MAX;
    x = countStepsTo1(n-1);
    if (n%2 == 0)
        y = countStepsTo1(n/2);
    if (n%3 == 0)
        z = countStepsTo1(n/3);
    return min(z,min(x,y)) + 1;
}
//memoization - linear time- top-down- recursive
int countStepsTo1_helper(int n,int* ans){
    if (n==1)
        return 0;
    if (ans[n] != -1)
        return ans[n];
    
    int x,y,z;
    y = INT_MAX;
    z = INT_MAX;
    x = countStepsTo1_helper(n-1,ans);
    if (n%2 == 0)
        y = countStepsTo1_helper(n/2,ans);
    if (n%3 == 0)
        z = countStepsTo1_helper(n/3,ans);
    ans[n] = min(z,min(x,y)) + 1;
    return ans[n];

}
int countStepsTo1_2(int n){
    int* ans = new int[n+1];
    for (int i=0; i<n+1; i++)
        ans[i] = -1;
    return countStepsTo1_helper(n,ans);

}
//dynamic programming -iterative-linear time - bottom-up
int countStepsTo1_3(int n){

    int* ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 0;
    
    for (int i = 2; i <= n; i++){
        int x,y,z;
        y = INT_MAX;
        z = INT_MAX;
        x = ans[i-1];
        if (i%2 == 0)
            y = ans[i/2];
        if (i%3 == 0)
            z = ans[i/3];
        ans[i] = min(x,min(y,z)) + 1;
    }
    return ans[n];

}
#include <bits/stdc++.h>
//recursion-exponential
int minCount_1(int n){
    
    if (n <= 1)
        return n;
    int min_count = INT_MAX;
    int small_min_count;
    for (int i = 1; i <= sqrt(n); i++){
        small_min_count = minCount(n - (i*i));
        if (small_min_count < min_count)
            min_count = small_min_count;
    }
    return min_count + 1;
}
//memoization-linear-recursive-top-down
//linear-time -drastic-improvement

int minCount_helper(int n,int* ans){
    if (n <= 1)
        return n;
    
    if (ans[n] != -1)
        return ans[n];
    
    int min_count = INT_MAX;
    int small_min_count;
    for (int i = 1; i <= sqrt(n); i++){
        small_min_count = minCount_helper(n - (i*i),ans);
        if (small_min_count < min_count)
            min_count = small_min_count;
    }
    ans[n] = min_count + 1;
    return ans[n];
}
int minCount_2(int n){
    
    int *ans = new int[n+1];
    for (int i = 0; i <= n; i++)
        ans[i] = -1;
    return minCount_helper(n,ans);
}
//finally-dynamic-programming
//linear-time-bottom-up-iterative
//cleanest-code-among-all

int minCount_3(int n){
    
    int *ans = new int[n+1];
    ans[0] = 0;
    ans[1] = 1;
    
    
    for (int i = 2; i <= n; i++){
        int min_count = INT_MAX;
        for (int j = 1; j <= sqrt(i); j++){
            if (min_count > ans[i - (j*j)])
                min_count = ans[i - (j*j)];
        }
        ans[i] = min_count + 1;
    }

    return ans[n];
}

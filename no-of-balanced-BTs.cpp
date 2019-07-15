//given h=height, find possible no. of *balanced* Binary Trees of height h
//result in modulo of (10^9)+7

//brute-force-recursive-exponential-O(2^h)-same as fibonacci
#include<bits/stdc++.h>
int balancedBTs(int h) {
    if (h <= 1){
        return 1;
    }
    int m = (int)(pow(10,9)) + 7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);
    int t1 = (int)(((long)(x)*x)%m);
    int t2 = (int)(((long)(x)*y*2)%m);
    int ans = ((t1 + t2)%m);
    return ans;
}

//memoization-linear-O(h)-top-down
int BT_helper(int h, int* ans){
    if (h <= 1){
        return 1;
    }
    
    if (ans[h] != -1)
        return ans[h];
    
    int m = (int)(pow(10,9)) + 7;
    int x = BT_helper(h-1, ans);
    int y = BT_helper(h-2, ans);
    int t1 = (int)(((long)(x)*x)%m);
    int t2 = (int)(((long)(x)*y*2)%m);
    int output = ((t1 + t2)%m);
    ans[h] = output; 
    return ans[h];
}
int binaryTreesOfHeightH_1(int h) {
    int* ans = new int[h+1];
    for (int i = 0; i <= h; i++)
        ans[i] = -1;
    return BT_helper(h, ans);

}
//Dynamic-Programming-O(h)- space requirement(auxiliary) - O(h)
int binaryTreesOfHeightH_2(int h) {
    int *ans = new int[h+1];
    ans[0] = 1;
    ans[1] = 1;
    
    int m = (int)(pow(10,9)) + 7;
    int x,y,t1,t2,out;
    for (int i = 2; i <= h; i++){
        x = ans[i - 1];
        y = ans[i - 2];
        t1 = (int)(((long)(x)*x)%m);
        t2 = (int)(((long)(x)*y*2)%m);
        out = (t1 + t2)%m;
        ans[i] = out;
    }
    return ans[h];
}





//given weights array,values array,
//max Weight W and n = no. of items
//either pick item or leave item 
//recursive soln, worst case time O(2^n)
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int knapsack(int* weights, int* values, int n, int maxWeight){

    if (maxWeight <= 0 || n == 0)
        return 0;
    
    int v2, ans;
    //leave item
    int v1 = knapsack(weights + 1, values + 1, n - 1, maxWeight);
    if (weights[0] <= maxWeight){
        //pick item
        v2 = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0]);
        ans = max(v1, v2 + values[0]);
    }
    else {
        ans = v1;
    }
    return ans;
}
//memoization O(n*W)
int knapsack(int* weights, int* values, int n, int maxWeight, int** output){

    if (maxWeight == 0 || n == 0)
        return 0;
    
    if (output[n][maxWeight] != -1)
        return output[n][maxWeight];
    
    int v2, ans;
    //leave item
    int v1 = knapsack(weights + 1, values + 1, n - 1, maxWeight, output);
    if (weights[0] <= maxWeight){
        //pick item
        v2 = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], output);
        ans = max(v1, v2 + values[0]);
    }
    else {
        ans = v1;
    }
    
    output[n][maxWeight] = ans;
    return ans;
}
int knapsack(int* weights, int* values, int n, int maxWeight){
    int** output = new int*[n + 1];
    for (int i = 0; i <= n; i++){
        output[i] = new int[maxWeight + 1];
        for (int j = 0; j <= maxWeight; j++)
            output[i][j] = -1;
    }
    return knapsack(weights, values, n, maxWeight, output);
}
//dynamic programming - 1

int knapsack(int* weights, int* values, int n, int maxWeight){
    int** output = new int*[n + 1];
    for (int i = 0; i < n+1; i++)
        output[i] = new int[maxWeight + 1];
    

    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= maxWeight; j++){
            if (i == 0 || j == 0)
                output[i][j] = 0;
            else if (weights[i - 1] <= j)
                output[i][j] = max(output[i - 1][j], values[i - 1] + output[i - 1][j - weights[i - 1]]);
            else
                output[i][j] = output[i - 1][j];
        }
    }
    
    return output[n][maxWeight];

}
//dynamic programming - 2
int knapsack(int* weights, int* values, int n, int maxWeight){
    
    int* outputPrev = new int[maxWeight + 1];
    int* outputCurr = new int[maxWeight + 1];
    for (int i = 0; i <= maxWeight; i++)
        outputPrev[i] = 0;
    
    

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= maxWeight; j++){
            if (weights[i - 1] > j)
                outputCurr[j] = outputPrev[j];
            else{
                outputCurr[j] = max(values[i - 1] + outputPrev[j - weights[i - 1]], outputPrev[j]);
            }
        }
        outputPrev = outputCurr;
        outputCurr = new int[maxWeight + 1];
    }
    
    return outputPrev[maxWeight];

}
//dynamic-programming-3 best solution
int knapsack(int* weights, int* values, int n, int maxWeight){
    int **dp = new int *[2];
    dp[0] = new int[maxWeight+1];
    dp[1] = new int[maxWeight+1];

    int id = 0;
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= maxWeight; w++){
            if(i == 0 || w == 0) dp[id][w] = 0;

            if(weights[i] > w){
                dp[id][w] = dp[id^1][w];
            }
            else{
                int a = values[i]+dp[id^1][w-weights[i]];
                int b = dp[id^1][w];

                dp[id][w] = max(a, b);
            }
        }
        id = id^1;
    }

    return dp[id^1][maxWeight];
}


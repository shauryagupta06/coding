//A thief wants to loot houses. 
//He knows the amount of money in each house. 
//He cannot loot two consecutive houses. 
//Find the maximum amount of money he can loot.
//eg. 5 100 5 1 200 , ans: 300
//recursive (TLE)
#include<bits/stdc++.h>
int getMaxMoney(int arr[], int n){
    
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];
    
    int x = getMaxMoney(arr + 1, n - 1);
    int y = getMaxMoney(arr + 2, n - 2) + arr[0];
    return (x > y)?x:y;
    
}
//dynamic-programming - linear
int max (int x, int y){
    return (x > y)?x:y;
}
int getMaxMoney(int arr[], int n){
    int* output = new int[n+1];
    output[n] = 0;
    output[n-1] = arr[n-1];
    for (int i = n - 2; i >= 0; i--){
        output[i] = max(output[i + 1], output[i + 2] + arr[i]);
    }
    return output[0];
}

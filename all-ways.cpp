//recursive,O(2^(x^(1/n)))
#include<bits/stdc++.h>
int allWays_helper(int* arr, int size, int x, int n){
    if (x == 0)
        return 1;
    else if (size == 0)
        return 0;
    int ans1 = allWays_helper(arr + 1, size - 1, x, n);
    int pton = (int)(pow(arr[0],n));
    if (pton > x)
        return ans1;
    else{
        int ans2 = allWays_helper(arr + 1, size - 1, x - pton, n);
        return ans1 + ans2;
    }
    
}
int allWays(int x, int n) {
    float nth = (float)(n);
    int lim = (int)(pow(x, (1/nth)));
    int* arr = new int[lim];
    for (int i = 0; i < lim; i++)
        arr[i] = i + 1;
    cout<<endl;
    return allWays_helper(arr, lim, x, n);
}
//without taking extra array
int allWays_helper(int curSize, int totalSize, int x, int n){
    if (x == 0)
        return 1;
    else if (curSize == 0)
        return 0;
        int pton = (int)(pow(totalSize - curSize + 1,n));
    int ans1 = allWays_helper(curSize - 1, totalSize, x, n);
    if (pton > x)
        return ans1;
    else{
        int ans2 = allWays_helper(curSize - 1,totalSize, x - pton, n);
        return ans1 + ans2;
    }
    
}
int allWays(int x, int n) {
    float nth = (float)(n);
    int lim = (int)(pow(x, (1/nth)));
    return allWays_helper(lim, lim, x, n);
}
//memoization , output array of size (lim+1) * (x+1)
//where lim = nth root of x converted to integer (ceiling)
//O(pow(x,(1/n))*x) time O(pow(x,(1/n))*x) space
// i.e. O(x ^ ((n+1)/n)) time and space 
int allWays_helper(int curSize, int totalSize, int x, int n, int** output){
    if (x == 0)
        return 1;
    else if (curSize == 0)
        return 0;
    
    if (output[curSize][x] != -1)
        return output[curSize][x];
    
    int pton = (int)(pow(totalSize - curSize + 1,n));
    int ans;
    
    int ans1 = allWays_helper(curSize - 1, totalSize, x, n, output);
    if (pton > x)
        ans = ans1;
    else{
        int ans2 = allWays_helper(curSize - 1,totalSize, x - pton, n, output);
        ans = ans1 + ans2;
    }
    
    output[curSize][x] = ans;
    
    return ans;
    
}
int allWays(int x, int n) {
    float nth = (float)(n);
    int lim = (int)(pow(x, (1/nth)));
    int** output = new int*[lim + 1];
    for (int i = 0; i <= lim; i++){
        output[i] = new int[x + 1];
        for (int j = 0; j <= x; j++){
            output[i][j] = -1;
        }
    }
    return allWays_helper(lim, lim, x, n, output);
}
//dynamic-programming
//O(x ^ ((n+1)/n)) time and space - not best dp
int allWays(int x, int n) {
    float nth = (float)(n);
    int lim = (int)(pow(x,(1/nth)));
    
    int** output = new int*[lim + 1];
    for (int i = 0; i <= lim; i++)
        output[i] = new int[x + 1]; 
    
    for (int i = 0; i <= lim; i++)
        output[i][0] = 1;
    
    for (int j = 1; j <= x; j++)
        output[0][j] = 0;
    
    for (int i = 1; i <= lim; i++){
        for (int j = 1; j <= x; j++){
            int pton = (int)(pow(lim - i + 1,n));
            if (pton <= j)
                output[i][j] = output[i - 1][j] + output[i - 1][j - pton];
            else
                output[i][j] = output[i - 1][j];
        }
    }
    
    return output[lim][x];
}
//dynamic-programming best solution
//O(x ^ ((n+1)/n)) time O(x) space

int allWays(int x, int n) {
    float nth = (float)(n);
    int lim = (int)(pow(x,(1/nth)));
    
    int** output = new int*[2];
    output[0] = new int[x + 1];
    output[1] = new int[x + 1];
    

    int id = 0;
    output[0][0] = 1;
    output[1][0] = 1;
    for (int i = 0; i <= lim; i++){
        
        int pton = (int)(pow(lim - i + 1,n));
        for (int j = 0; j <= x; j++){
            
            if (i == 0 && j != 0) {
                output[id][j] =0;
                break;
            }
            

            if (pton <= j){
                output[id][j] = output[id^1][j] + output[id^1][j - pton];
            }
            else
                output[id][j] = output[id^1][j];
        }

        id = id^1;
    }
    
    return output[id^1][x];
}



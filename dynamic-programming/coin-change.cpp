/*You are given an infinite supply of coins of each of 
denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to 
figure out the total number of ways W, in which you can make
 change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible. */

//eg. n = 3
//denominations[] = 1 2 3
//value = 4
//Ans: 4
//Explanation: Number of ways are - 4 total i.e. 
//(1,1,1,1), (1,1, 2), (1, 3) and (2, 2).


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int n = numDenominations;
    int v = value;
    int** dp = new int*[v + 1];
    for(int i = 0; i <= v; i++){
        dp[i] = new int[n];
    }
    for (int i = 0; i < n; i++){
        dp[0][i] = 1;
    }
    for (int i = 1; i <= v; i++){
        for (int j = 0; j < n; j++){
            int x, y;
            //including denomination denominations[j]
            x = (i - denominations[j] >= 0) ? dp[i - denominations[j]][j] : 0;
            //excluding denomination denominations[j]
            y = (j - 1 >= 0) ? dp[i][j - 1] : 0;
            
            dp[i][j] = x + y;
        }
    }
    return dp[v][n - 1];
}

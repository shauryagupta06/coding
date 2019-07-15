//You are given an infinite supply of coins of each of 
//denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
//You need to figure out the total number of ways W, 
//in which you can make change for Value V 
//using coins of denominations D.
//Note : Return 0, if change isn't possible.

//eg v = 4 , n = 3 , den= [1,2,3]
//ans: 4 ways (1) 1,1,1,1 (2) 1,1,2 (3) 2,2 (4) 3,1

//dynamic-programming
//O(n * v) time O(n * v) space
//where n = no. of denominations , v = value to be obtained


int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    int** output = new int*[numDenominations];
    for (int i = 0; i < numDenominations; i++)
        output[i] = new int[value+1];
    
    for (int i = 0; i <= numDenominations - 1; i++)
        output[i][0] = 1;

    for (int i = 0; i <= numDenominations - 1; i++){
        for (int j = 1; j <= value; j++){
            int count1 = 0;
            int count2 = 0;
            if (i - 1 >= 0 ){
                count1 = output[i - 1][j];
            }
            if (denominations[i] <= j){
                count2 = output[i][j - denominations[i]];
            }
                output[i][j] = count1 + count2;
        }

    }
    return output[numDenominations - 1][value];
    return 0;
}

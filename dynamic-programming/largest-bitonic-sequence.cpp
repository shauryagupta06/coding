/*You are given an array of positive integers as input. 
Write a code to return the length of the largest such 
sub-array in which the values are arranged first in 
strictly ascending order and then in strictly descending 
order.
Such a sub-array is known as bitonic sub-array. A purely 
increasing or purely decreasing subsequence will also be 
considered as a bitonic sequence with the other part empty. */
//Note: Ans should be a subsequence(deleting elements in b/w)

//APPROACH: Maintain a LIS in inc array and LDS in dec array
//index i with max value inc[i] + dec[i] - 1 will be 
//the middle index, and ans will be inc[i] + dec[i] - 1

//O(n^2) time O(n) time 

int longestBitonicSubarray(int *input, int n) {

    int* inc = new int[n];
    int* dec = new int[n];
    inc[0] = 1;
    for (int i = 1; i < n; i++){
        inc[i] = 1;
        for (int j = i - 1; j >= 0; j--){
            if (input[j] >= input[i]){
                continue;
            }
            int possibleAns = inc[j] + 1;
            if (possibleAns > inc[i]){
                inc[i] = possibleAns;
            }
        }
    }
    
    dec[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--){
        dec[i] = 1;
        for (int j = i + 1; j < n; j++){
            if (input[j] >= input[i]){
                continue;
            }
            int possibleAns = dec[j] + 1;
            if (possibleAns > dec[i]){
                dec[i] = possibleAns;
            }
        }
    }
    int ans = inc[0] + dec[0] - 1;
    for (int i = 0; i < n; i++){
        if (inc[i] + dec[i] - 1 > ans){
            ans = inc[i] + dec[i] - 1;
        }
    }
    return ans;
}


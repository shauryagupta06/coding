//eg.20 2 4 6 1 10, ans: 4, lis: 2 4 6 10
//print only length of longest inc. subsequence 
//dynamic programming
//time O(n^2)

//output[i] = length of lis ending at index i, 
//i.e. length of lis of arr[0...i]
//for output[i] , check for all 0 to i-1 outputs
//if increasing subsequence i.e. possible , add 1
//after adding 1 to all possible subsequences, 
//select the one which gives max at i
//after filling output array
//traverse output and select max value = length of lis

using namespace std;

int lis(int arr[], int n) {
    int* output = new int[n];
    output[0] = 1;
    for (int i = 1; i < n; i++){
        output[i] = 1;
        int curMax;
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i]){
                curMax = output[j] + 1;
                if (curMax > output[i])
                    output[i] = curMax;
            }
        }
    }
    int best = output[0];
    for (int i = 1; i < n; i++){
        if (output[i] > best)
            best = output[i];
    }
    return best;
}
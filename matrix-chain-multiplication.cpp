//Given a chain of matrices A1, A2, A3,.....An, 
//you have to figure out the most efficient way to multiply
// these matrices i.e. determine where to place parentheses 
//to minimise the number of multiplications.

//You will be given an array p[] of size n + 1. 
//Dimension of matrix Ai is p[i - 1]*p[i].
// You need to find minimum number of multiplications 
//needed to multiply the chain.

//APPROACH: Find the best bigger bracket. 
//Get all answers and take the min ans
//eg. M1,M2,M3,M4 four matrices
//dimension array: [p0, p1, p2, p3, p4],s = 0,e = 4, 3 answers
//(1) (M1)*(M2*M3*M4) k = 1, ans1 = (0,1) + (1,4) + p0*p1*p4
//(2) (M1*M2)*(M3*M4) k = 2, ans2 = (0,2) + (2,4) + p0*p2*p4
//(3) (M1*M2*M3)*(M4) k = 3, ans3 = (0,3) + (3,4) + p0*p3*p4
//final ans to be returned:" ans = min(ans1,ans2,ans3)

//recursive solution 
//O(n^n) time
int mcm(int* p, int s, int e){
    if (s == e || s == e - 1)
        return 0;
    int min_ans = INT_MAX;
    for (int k = s + 1; k <= e - 1; k++){
        int curr_ans = mcm(p, s, k) + mcm(p, k, e) + (p[s]*p[k]*p[e]);
        if (curr_ans < min_ans)
            min_ans = curr_ans;
    }
    return min_ans;
}
int mcm(int* p, int n){
    return mcm(p, 0, n);
}

//dynamic-programming
//O(n^2 * k calls) time
//O(n^2) space
int mcm(int* p, int n){
    //dynamic allocation initializes all cells of the array to 0
    int** output = new int*[n + 1];
        for (int i = 0; i <= n ; i++)
            output[i] = new int[n + 1];
    //not needed, just to explain the base case
    for (int i = 0; i <= n ; i++){
        output[i][i] = 0;
        if (i + 1 <= n)
            output[i][i + 1] = 0;
    }
    

    for (int i = n - 2 ; i >= 0; i--){
        for (int s = 0; s <= i; s++){
            int e = s + (n - i);
            int min_ans = INT_MAX;
            for (int k = s + 1; k <= e - 1; k++){
                int curr_ans = output[s][k] + output[k][e] + p[s]*p[k]*p[e];
                if (curr_ans < min_ans)
                    min_ans = curr_ans;
            }
            output[s][e] = min_ans;
        }

    }
    return output[0][n];
}

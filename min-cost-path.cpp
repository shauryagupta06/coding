//a matrix is given of size m*n
//find the minimum cost path fro reaching from (0,0) cell to (m-1,n-1) cell
//possible movements : (i+1,j) (i,j+1) (i+1,j+1)

//brute-force very-bad-time 
//calls for all three directions(conditional) and returns (min + self_cost) as answer

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath_helper(int **input, int m, int n, int i, int j){
    if (i == m-1 && j == n-1)
        return input[m-1][n-1];
    
    int x,y,z;
    x = INT_MAX;
    y = INT_MAX;
    z = INT_MAX;
    
    if (i+1 < m)
        x = minCostPath_helper(input, m, n, i+1, j);
    if (j+1 < n)
        y = minCostPath_helper(input, m, n, i, j+1);
    if (i+1 < m && j+1 < n)
        z = minCostPath_helper(input, m, n, i+1, j+1);
    
    return min(x,min(y,z)) + input[i][j];
    
    
}
int minCostPath_1(int **input, int m, int n) {
    return minCostPath_helper(input, m, n, 0, 0);
}

//memoization top-down O(m*n) time , O(m*n) space

int minCostPath_helper(int **input, int m, int n, int i, int j, int** output){
    if (i == m-1 && j == n-1)
        return input[m-1][n-1];
    
    if (output[i][j] != -1)
        return output[i][j];
    
    int x,y,z;
    x = INT_MAX;
    y = INT_MAX;
    z = INT_MAX;
    
    if (i+1 < m)
        x = minCostPath_helper(input, m, n, i+1, j, output);
    if (j+1 < n)
        y = minCostPath_helper(input, m, n, i, j+1, output);
    if (i+1 < m && j+1 < n)
        z = minCostPath_helper(input, m, n, i+1, j+1, output);
    
    int a = min(x,min(y,z)) + input[i][j];
    
    output[i][j] = a;
    
    return a;
        
}
int minCostPath_2(int **input, int m, int n) {
    int** output = new int*[m];
    for (int i = 0; i < m; i++)
        output[i] = new int[n];
    
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            output[i][j] = -1;
        
    return minCostPath_helper(input, m, n, 0, 0, output);
}
//Dynamic programming O(m*n) time , O(m*n) space bottom-up
int minCostPath_3(int **input, int m, int n) {
    int** output = new int*[m];
    
    for (int i = 0; i < m; i++){
        output[i] = new int[n];
    }
 
    output[m-1][n-1] = input[m-1][n-1];
    
    int x,y,z;
    for (int i = m-1; i >= 0; i--){
        for (int j = n-1; j >= 0; j--){
            if (i != m-1 || j != n-1){
            
                x = INT_MAX;
                y = INT_MAX;
                z = INT_MAX;
                if (i+1 < m)
                    x = output[i+1][j];
                if (j+1 < n)
                    y = output[i][j+1];
                if (i+1 < m && j+1 < n)
                    z = output[i+1][j+1];
                output[i][j] = min(x,min(y,z)) + input[i][j];
            }
        }
    }     
    return output[0][0];
}


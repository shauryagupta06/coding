//Given a n*m matrix which contains only 0s and 1s, 
//find out the size of maximum square sub-matrix with all 0s. 
//You need to return the size of square with all 0s.
//solved through dp

//eg. n = 4, m = 5
//1 0 0 0 0
//1 1 0 0 0
//1 0 0 0 0
//1 1 1 0 0
//ans : 3

//APPROACH 1: create output array of size n*m
//output[i][j]=side length of max square submatrix 
//with all zeros, ending at index (i,j) in input matrix.
//for 0th row or 0th column, 
//output[i][j] = 0 for input[i][j] = 1 and vice versa.
//if input[i][j] = 1, output[i][j] = 0 else
//for output[i][j] check, output[i-1][j-1] = ans
//check ans no. of blocks horizontally = h and vertically = v
//in input array moving away from index(i,j), stop if != 0
//if all zeros , output[i][j] = min(h,v) + 1;
//time = O(n^2 * n) = O(n^3)
//space = O(n^2) , both for n = m

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int min(int a, int b){
    return (a < b)?a:b;
}
int maxOutput(int** output,int row, int col){
    int max_cell = INT_MIN;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (output[i][j] > max_cell)
                max_cell = output[i][j];
        }
    }
    return max_cell;
}
void printOutput(int** output,int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int** output = new int*[row];
    for(int i = 0; i < row; i++)
        output[i] = new int[col];
    
    for (int i = 0; i < row ; i++)
        output[i][0] = arr[i][0]^1;
    
    for (int j = 1; j < col; j++)
        output[0][j] = arr[0][j]^1;
    
    
    for (int i = 1; i < row; i++){
        for (int j = 1; j < col; j++){
            if (arr[i][j] == 1)
                output[i][j] = 0;
            else{
                int h,v;
                h = 0;
                v = 0;
                int ans = output[i - 1][j - 1];
                for (int k = j - 1; k >= j - ans; k--){
                    if (arr[i][k] == 0){
                        h++;
                    }
                    else{
                        break;
                    } 
                }
                for (int l = i - 1; l >= i - ans; l--){
                    if (arr[l][j] == 0){
                        v++;
                    }
                    else{
                        break;
                    } 
                }
                output[i][j] = min(h,v) + 1;
            }
        }
        //printOutput(output, row, col);
    }
    //printOutput(output, row, col);
    return maxOutput(output, row, col);
}

//APPROACH 2: starting and base case same as approach 1
//if output[i][j]=0,check, output[i-1][j-1] = ans1,
//output[i][j - 1] = ans2,output[i-1][j] = ans3,
//output[i][j] = min(ans1,ans2,ans3) + 1;
//time = O(n^2) : better solution
//space = O(n^2) , both for n = m

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int min(int a, int b){
    return (a < b)?a:b;
}
int maxOutput(int** output,int row, int col){
    int max_cell = INT_MIN;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if (output[i][j] > max_cell)
                max_cell = output[i][j];
        }
    }
    return max_cell;
}
void printOutput(int** output,int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int** output = new int*[row];
    for(int i = 0; i < row; i++)
        output[i] = new int[col];
    
    for (int i = 0; i < row ; i++)
        output[i][0] = arr[i][0]^1;
    
    for (int j = 1; j < col; j++)
        output[0][j] = arr[0][j]^1;
    
    
    for (int i = 1; i < row; i++){
        for (int j = 1; j < col; j++){
            if (arr[i][j] == 1)
                output[i][j] = 0;
            else{
                int ans1 = output[i - 1][j - 1];
                int ans2 = output[i][j - 1];
                int ans3 = output[i - 1][j];
                output[i][j] = min(ans1, min(ans2, ans3)) + 1;
            }
        }
        //printOutput(output, row, col);
    }
    //printOutput(output, row, col);
    return maxOutput(output, row, col);
}


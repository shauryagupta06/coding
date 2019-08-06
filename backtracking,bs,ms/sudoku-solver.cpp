//Given 9 * 9 grid, where nos are from 1 to 9
//0 means not filled , return true if it has a solution
//else false 

//APPROACH: Backtracking, go to each cell one by one
//If we reach 9th row, we have a solution, return true,
//If col out of range, i.e. > 8, return next row, 0th col

//If cell(r,c) is already filled, return true
//Else check for all options from i = 1 to 9
//If possible to place i at cell(r,c), recurse for
//next cell, if it returns true, it means that all subsequent
//cells have been filled, so curr cell(r,c) will also
//return true
//If it returns false, there are unfilled cells which had no 
//option left, so curr cell(r,c) will make itself unfilled
//and will try next options
//If none of the options return true,(r,c) will return false

#include<bits/stdc++.h>
bool check(int board[][9], int r, int c, int k){

    for (int i = 0; i < 9; i++){
        if (board[r][i] == k){
            return false;
        }
        if (board[i][c] == k){
            return false;
        }
    }
    int sr = r - (r % 3);
    int sc = c - (c % 3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[sr + i][sc + j] == k){
                return false;
            }
        }
    }
    return true;
}
bool sudoku(int board[][9], int r, int c){
    if (r == 9){
        return true;
    }
    if (c == 9){
        return sudoku(board, r + 1, 0);
    }
    if (board[r][c] != 0){
        return sudoku(board, r, c + 1);
    }
    for (int i = 1; i <= 9 ; i++){
        if (check(board, r, c, i)){
            board[r][c] = i;
            if (sudoku(board, r, c + 1)){
                return true;
            }
        }
        board[r][c] = 0;
    }
    return false;
}
bool sudokuSolver(int board[][9]){

    return sudoku(board, 0, 0);
}


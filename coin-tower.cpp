//Whis and Beerus form a tower of N coins and 
//make a move in alternate turns . 
//Beerus plays first .
//In one move player can remove 1 or X or Y coins from the tower
//The person to make the last move wins the Game . 
//Print who wins the game

//APPROACH: I am Beerus i.e. one of the players, here 
//I am the one who plays first
//At every stage of i = no. of coins left in the tower
//I'll find whether I'll win(output[i] = 1) or lose(output[i] = 0)
//If I am losing at n-x, I will win at n and vice versa.
//Same case for n - 1 and n - x
//I'll find xor of ans with 1 for all the three answers
//I am at n, after xoring n-1,n-x, n-y 
//I get win or lose answers for all three situations
//If even one the answers is 1, I will win at n,output[n] = 1
//If all three answers are 0, I have no option, I will lose at n

//dynamic programming
//O(n) time and O(n) space 

#include<bits/stdc++.h>

string solve(int n, int x, int y)
{
    int* output = new int[n + 1];
    
    //1 = Beerus(player to start) wins at stage i
    //0 = Beerus looses at stage i
    
    output[1] = 1;
    output[x] = 1;
    output[y] = 1;
    for (int i = 2; i <= n ; i++){
        
        if (i != x && i != y){
            int ans2 = INT_MIN;
            int ans3 = INT_MIN;
            int ans1 = output[i - 1]^1;
            if (i - x >= 1)
                ans2 = output[i - x]^1;
            if (i - y >= 1)
                ans3 = output[i - y]^1;
        
            output[i] = max(ans1, max(ans2, ans3));
        }
    }

    string s;
    if (output[n] == 1)
        s = "Beerus";
    else
        s = "Whis";
    return s;
}


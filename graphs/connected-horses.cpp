//N*M size board with similar arrangement of black and 
//white cells.
//A few of these cells have Horses placed over them. 
//Each horse is unique. Now these horses can jump any of
//8 positions only if there is another horse on one of 
//the 8-positions and then both the horses will swap their 
//positions. This swapping can happen infinitely times.

//Find no. of ways that the horses occupy the board! 
//Given the state of the board, calculate answer.
//Since ans may be large, calculate in modulo 10^9+7

//Connected-components problem, we take the board m,
//Take input and mat[i][j] = 1, if coordinate (i,j) has 
//a horse, else it is 0
//For each cell(total n*m cells), call dfs function on i,j
//if there is a horse at i,j
//For i,j , dfs function will explore all the 8 valid positions
//if there is a horese on the position, means there two
//horses are adjacent in the fraph, i.e. the horses on any
//of the 8 positions are neighbors of horse at(i,j)
//call dfs on each neighbor, to get the count of no. of 
//horses connected to that neighbor
//dfs(i,j) will return count of all connected horses to 
//i,j and in the process, will mark all horses as 2 i.e.
//visited, now next dfs call will be on next unvisited horse

//if c1, c2, ..cn, ane the counts of horses in each connected
//component 1, then ans = c1! * c2! * c3!...*cn!

#include<bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long int
int n, m;
ll dfs (int** mat, int i, int j){
    mat[i][j] = 2;
    ll t = 1;
    if(i - 1 > 0 && j - 2 > 0 && mat[i - 1][j - 2] == 1)
        t += dfs(mat, i - 1, j - 2);
    if(i - 1 > 0 && j + 2 <= m && mat[i - 1][j + 2] == 1)
        t += dfs(mat, i - 1, j + 2);
    if(i - 2 > 0 && j - 1 > 0 && mat[i - 2][j - 1] == 1)
        t += dfs(mat, i - 2, j - 1);
    if(i - 2 > 0 && j + 1 <= m && mat[i - 2][j + 1] == 1)
        t += dfs(mat, i - 2, j + 1);
    if(i + 1 <= n && j - 2 > 0 && mat[i + 1][j - 2] == 1)
        t += dfs(mat, i + 1, j - 2);
    if(i + 1 <= n && j + 2 <= m && mat[i + 1][j + 2] == 1)
        t += dfs(mat, i + 1, j + 2);
    if(i + 2 <= n && j - 1 > 0 && mat[i + 2][j - 1] == 1)
        t += dfs(mat, i + 2, j - 1);
    if(i + 2 <= n && j + 1 <= m && mat[i + 2][j + 1] == 1)
        t += dfs(mat, i + 2, j + 1);
    return t;
}
ll fact(ll t){
    ll a = 1;
    for (ll i = 1; i <= t; i++){
        a = (a*i)%mod;
    }
    return a;
}
void solve(int** mat, int n, int m){
    ll ans = 1;
    ll t;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j++){
            if (mat[i][j] == 1){
                t = dfs(mat, i, j);
                ans = (ans*fact(t))%mod;
            }
        }
    }
    cout<< ans << endl;
}
int main()
{
    int t; cin>> t;
    while (t--){
        int q;
        cin >> n >> m >> q;
        int** mat = new int*[n + 1];
        for (int i = 0; i <= n; i++){
            mat[i] = new int[m + 1];
            for (int j = 0; j <= m; j++){
                mat[i][j] = 0;
            }
        }
        for (int i = 0; i < q; i++){
            int x, y;
            cin >> x >> y;
            mat[x][y] = 1;
        }
        solve(mat, n, m);
    }
	return 0;
}

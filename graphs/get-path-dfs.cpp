//Print path from given x to y
//DFS approach - not the shortest path
//Returning ans vector from adjacent vertices
//If not empty, pushing back x into ans vector
//If empty, try other options
//If none of the options return non empty ans
//Means no possible path, return empty vector ans

//Base case: if x and y are same, it is already a path
//return vector ans = {x}

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> getPathHelper(int** mat, int V, int x , int y, bool* visited){
    if (x == y){
        vector<int> ans;
        visited[x] = true;
        ans.push_back(x);
        return ans;
    }
    visited[x] = true;
    vector<int> ans;
    for (int i = 0; i < V ; i++){
        if (i == x){
            continue;
        }
        if (mat[x][i] == 1 && !visited[i]){
            ans = getPathHelper(mat, V, i, y, visited);
            if (!ans.empty()){
                ans.push_back(x);
                return ans;
            }
            else{
                continue;
            }
        }
    }
    return ans;
}
vector<int> getPath(int** mat, int V, int x, int y){
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    return getPathHelper(mat, V, x, y, visited);
}
int main()
{
    int V, E, tempX, tempY;
    cin >> V >> E;
    int** mat = new int*[V];
    for (int i = 0; i < V; i++){
        mat[i] = new int[V];
        for (int j = 0; j < V; j++){
            mat[i][j] = 0;
        }
    }
    for (int i = 0; i < E; i++){
        int f, s;
        cin>>f>>s;
        mat[f][s] = 1;
        mat[s][f] = 1;
    }
    cin >> tempX >> tempY;
    vector<int> ans;
    ans = getPath(mat, V, tempX, tempY);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    

    return 0;
}

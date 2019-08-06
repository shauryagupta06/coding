//Print path from given x to y
//BFS approach - shortest path
//ans vector to store ans, queue q, and int to int map path
//start by pushing x, for all the adjacent vertices to x,
//if == y, update map, and break from both loops
//else, push vertex to queue, update map, mark visited

//Note: map stores: key = end node, value = start node
//If path found(i.e. flag == 1), Track back through map
//set curr as y, keep updating current
//Keep pushing curr to ans vector till x found

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> getPathHelper(int** mat, int V, int x , int y, bool* visited){
    vector<int> ans;
    unordered_map<int, int> path;
    queue<int> q;
    int flag = 0;
    
    q.push(x);
    visited[x] = true;
    while (!q.empty()){
        int f = q.front();
        q.pop();
        for (int i = 0; i < V; i++){
            if (i == f){
                continue;
            }
            if (mat[f][i] == 1 && !visited[i]){
                if (i == y){
                    path[y] = f;
                    flag = 1;
                    break;
                }
                else{
                    q.push(i);
                    visited[i] = true;
                    path[i] = f;
                }
            }
        }
        if (flag == 1)
            break;
    }
    if (flag == 1){
        ans.push_back(y);
        int curr = y;
        while (curr != x){
            ans.push_back(path[curr]);
            curr = path[curr];
        }
        return ans;
    }
    else{
        return ans;
    }
    
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

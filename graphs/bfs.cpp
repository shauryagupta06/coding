//Using Adjacency matrix for storing graph
//Assuming vertices: 0  to V - 1
//Using queue to stare adjacent node
//Also maintaining a visited boolean map/array so that no
//node repeats
//eg. V = 5, E =  5
/* 0 2
0 4
4 2
3 4 
2 1*/
//ans : 0 2 4 1 3
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void print(int** mat, int V, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty()){
        int f = q.front();
        cout<< f <<" ";
        q.pop();
        for (int i = 0; i < V; i++){
           if (f == i){
               continue;
           }
            if (mat[f][i] == 1){
                if (visited[i]){
                    continue;
                }
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return;
}
int main() {
    int V, E;
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
    
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    print(mat, V, 0, visited);
    return 0;
}

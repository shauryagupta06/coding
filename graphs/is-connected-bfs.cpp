//We call funtion isConnectred function, and then BFSTraversal 
//starting vertex =  0
//After returning from BFSTraversal, visited array must 
//have all the vertices marked true which were a part of the
//connected component containing 0
//If any vertex left, it means it is not connected 
//to 0, means there is a disconnected component
//Note: Starting vertex can be anything form 0 to v - 1
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void BFSTraversal(int** mat, int V, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty()){
        int f = q.front();
        q.pop();
        for (int i = 0; i < V; i++){
           if (f == i){
               continue;
           }
            if (mat[f][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return;
}
bool isConnected(int** mat, int V){
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    BFSTraversal(mat, V, 0, visited);
    for (int i = 0; i < V; i++){
        if (!visited[i]){
            return false;
        }
    }
    return true;
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
    
    
    if (isConnected(mat, V))
        cout<<"true";
    else
        cout<<"false";
    
    
    for (int i = 0; i < V; i++){
        delete [] mat[i];
    }
    delete [] mat;
    return 0;
}
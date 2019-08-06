//As an improvisation, we call funtion DFS first
//It traverses(0 to v-1) throught the visited array and checks after
//each iteration if any vertex is yet left to be visited
//Calls print funtion on the left out vertex as starting point
//To begin with, 0 will be not visited, so first call on 0
//After returning from print, visited array must have all
//the vertices marked true which were a part of the
//connected component contaianing 0
//Call for unvisited vertices
//eg. V = 4, e = 2
//(0, 2) , (1, 3)
//ans : 0 2 1 3
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void print(int** mat, int V, int sv, bool* visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < V; i ++){
        if (i == sv){
            continue;
        }
        if (mat[sv][i] == 1){
            if (visited[i]){
                continue;
            }
            print(mat, V, i, visited);
        }
    }
    return ;
}
void DFS(int** mat, int V){
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    for (int i = 0; i < V; i++){
        if (!visited[i]){
            print(mat, V, i, visited);
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
    
    
    DFS(mat, V);
    
    for (int i = 0; i < V; i++){
        delete [] mat[i];
    }
    delete [] mat;
    return 0;
}

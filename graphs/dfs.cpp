//Using Adjacency matrix for storing graph
//Assuming vertices: 0  to V - 1
//Using recursion for calling into depth
//Also maintaining a visited boolean map/array so that no
//node repeats(prevent from getting into infinite call also)
//eg. V = 5, E =  5
/* 0 2
0 4
4 2
3 4 
2 1*/
//ans : 0 2 1 4 3
#include <iostream>
using namespace std;
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

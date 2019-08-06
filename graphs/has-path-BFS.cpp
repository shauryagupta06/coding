//Check if there is a path connecting v1 and v2
//BFS-Approach

#include <iostream>
#include<queue>
using namespace std;
bool hasPath(int** mat, int V, int start, int end, bool* visited){
    if (mat[start][end] == 1){
        return true;
    }
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()){
        int front = q.front();
        q.pop();
        for (int i = 0; i < V; i++){
            if (front == i){
                continue;
            }
            if (mat[front][i] == 1 && !visited[i]){
                if (i == end)
                    return true;
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
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
    int v1, v2;
    cin>>v1>>v2;
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    bool ans = hasPath(mat, V, v1, v2, visited);
    if (ans)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}

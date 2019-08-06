//We receive a vector of vector pointers from connectedComp
//function and print it
//BFS Approach-connectedComp:receive a vector pointer for every 
//unvisited vertex, sort and add it to 2D vector ans
//BFS func: everytime anything enters queue, add it to comp 
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void BFSTraversal(int** mat, int V, int sv, bool* visited, vector<int>* comp){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    comp->push_back(sv);
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
                comp->push_back(i);
            }
        }
    }
    return;
}
vector<vector<int>*> connectedComp(int** mat, int V){
    vector<vector<int>*> ans;
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }

    for (int i = 0; i < V; i++){
        if (!visited[i]){
            vector<int>* comp = new vector<int>();
            BFSTraversal(mat, V, i, visited, comp);
            sort(comp->begin(), comp-> end());
            ans.push_back(comp);
        }
    }
    
    return ans;
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
    
    vector<vector<int>*> ans;
    ans = connectedComp(mat, V);
    for(int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i] -> size(); j++){
            cout << ans[i]->at(j) <<" ";
        }
        cout << endl;
    }
    
    
    for (int i = 0; i < V; i++){
        delete [] mat[i];
    }
    delete [] mat;
    return 0;
}

//We receive a vector of vector pointers from connectedComp
//function and print it
//DFS Approach-connectedComp:receive a vector pointer for every 
//unvisited vertex, sort and add it to 2D vector ans
//DFS func: everytime add sv to comp 
#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void DFSTraversal(int** mat, int V, int sv, bool* visited, vector<int>* comp){
    visited[sv] = true;
    comp->push_back(sv);
    for (int i = 0; i < V; i ++){
        if (i == sv){
            continue;
        }
        if (mat[sv][i] == 1 && !visited[i]){
            DFSTraversal(mat, V, i, visited, comp);
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
            DFSTraversal(mat, V, i, visited, comp);
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


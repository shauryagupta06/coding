//We call funtion isConnectred function, and then DFSTraversal 
//starting vertex =  0
//After returning from DFSTraversal, visited array must 
//have all the vertices marked true which were a part of the
//connected component containing 0
//If any vertex left, it means it is not connected 
//to 0, means there is a disconnected component
//Note: Starting vertex can be anything form 0 to v - 1

void DFSTraversal(int** mat, int V, int sv, bool* visited){
    visited[sv] = true;
    for (int i = 0; i < V; i ++){
        if (i == sv){
            continue;
        }
        if (mat[sv][i] == 1 && !visited[i]){
            DFSTraversal(mat, V, i, visited);
        }
    }
    return;
}
bool isConnected(int** mat, int V){
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
    }
    DFSTraversal(mat, V, 0, visited);
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
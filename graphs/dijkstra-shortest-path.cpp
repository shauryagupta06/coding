//Find length shortest path from source, here 0 ,to
//all V vertices

//Maintain a visited, distance: dist array
//dist[i] : length of best path from 0 to i till now
//at the end dist[i]  will give the best path for i
//so ans : i dist[i]

//we decide a source, here 0, make its dist 0 and
//dist of others as infinite
//loop v(or v - 1) times(each time a vertex will be visited)
//find curr idx which has the min dist
//among unvisited indices, mark curr as visited
//explore neighbors of curr
//for each unvisited neighbor n, d = distance from source
//via curr to n = dist[curr] + (weight of curr to n)
//if d is lesser than already stored dist of n
//update better dist 

//after loop finishes,min distances are corr dist[i]
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void DijkstraAlgo(int** mat, int V, int E){
    bool* visited = new bool[V];
    int* dist = new int[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
        dist[i] = INT_MAX;
    }
    dist[0] = 0;
    
    for (int j = 0; j < V; j ++){
        int curr;
        int min_wt = INT_MAX;
        for (int i = 0; i < V ; i++){
            if (!visited[i]){
                if (dist[i] < min_wt){
                    curr = i;
                    min_wt = dist[i];
                }
            }
        }
        visited[curr] = true;
        for (int i = 0; i < V; i++){
            if (mat[curr][i] != 0 && !visited[i]){
                if (dist[curr] + mat[curr][i]  < dist[i]){
                    dist[i] = dist[curr] + mat[curr][i];
                }
            }
        }
    }
    for (int i = 0; i < V; i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    return;
}
int main()
{
    int V, E;
    cin >> V >> E;
    int** mat = new int*[V];
    for(int i = 0; i < V; i++){
        mat[i] = new int[V];
    }
    for (int i = 0; i < E; i++){
        int f, s, w;
        cin >> f >> s >> w;
        mat[f][s] = w;
        mat[s][f] = w;
    }
    DijkstraAlgo(mat, V, E);
    return 0;
}
//To reduce time, use Adjacency Matrix, use Priority
//Queue to get curr vertex, do not forget to update dist 
//in Priority Queue if dist is updated
//O((E + V)logV)
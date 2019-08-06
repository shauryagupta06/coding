//Maintain a visited, parent, weight array
//weight[i] : best edge from i till now
//at the end weight[i]  will give the best edge for i
//and parent[i] will give the other end of the best edge
//so edge : i parent[i] weight[i]

//we decide a source, here 0, make its weight 0 and
//weight of others as infinite
//loop v(or v - 1) times(each time a vertex will be visited)
//find curr idx which has the min weight 
//among unvisited indices, mark curr as visited
//explore neighbors of curr
//for each unvisited neighbor n, if edge from curr to n
//has lesser weight than already stored weight of n
//update better weight and make curr parent of n

//after loop finishes,MST edges lie from 1 to V-1
//O(V^2) time 
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void MSTPrims(int** mat, int V, int E){
    bool* visited = new bool[V];
    int* parent = new int[V];
    int* weight = new int[V];
    for (int i = 0; i < V; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    for (int j = 0; j < V; j ++){
        int curr;
        int min_wt = INT_MAX;
        for (int i = 0; i < V ; i++){
            if (!visited[i]){
                if (weight[i] < min_wt){
                    curr = i;
                    min_wt = weight[i];
                }
            }
        }
        visited[curr] = true;
        for (int i = 0; i < V; i++){
            if (mat[curr][i] != 0 && !visited[i]){
                if (mat[curr][i] < weight[i]){
                    weight[i] = mat[curr][i];
                    parent[i] = curr;
                }
            }
        }
    }
    for (int i = 1; i < V; i++){
        int s = (i <= parent[i])?i:parent[i];
        int l = (i + parent[i]) - s;
        cout<<s<<" "<<l<<" "<<weight[i]<<endl;
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
    MSTPrims(mat, V, E);
    return 0;
}
//To reduce time, use Adjacency Matrix, use Priority
//Queue to get curr vertex, do not forget to update weight 
//in Priority Queue if weight is updated
//O((E + V)logV)


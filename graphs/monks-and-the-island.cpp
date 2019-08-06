//Monk visits the land of Islands. There are a total of N 
//islands numbered from 1 to N. Some pairs of islands are 
//connected to each other by Bidirectional bridges running 
//over water.
//He is standing at Island #1 and wants to reach the 
//Island #N. Find the minimum the number of bridges 
//that he shall have to cross, if he takes the optimal route.

//Typical BFS application
//Island i is converted to i - 1 and shortest path
//is found b/w 0 and n - 1
//we maintain an array level for each vertex
//level of vertex 0 is 0 and we need to find the level
//of vertex n - 1
//bfs gives min level to reach n - 1 from 0
//loop is stopped when vertex (ev) is insreted in queue

#include<bits/stdc++.h>
using namespace std;
int findLevel(vector<int>* edges, int n, int sv, int ev){
    bool* visited = new bool[n];
    for (int i = 0; i < n ; i++){
        visited[i] = false;
    }
    if (sv == ev){
        return 0;
    }
    queue<int> q;
    int* level = new int[n];
    level[sv] = 0;
    q.push(sv);
    visited[sv] = true;
    int flag = 0;
    while (!q.empty()){
        int f = q.front();
        q.pop();
        for (int i = 0; i < edges[f].size(); i++){
            int nb = edges[f][i];
            if (!visited[nb]){
                q.push(nb);
                visited[nb] = true;
                level[nb] = level[f] + 1;
                if (nb == ev){
                    flag = 1;
                    break;
                }
            }
        }
        if (flag)
            break;
    }
    return level[ev];
}
int main()
{
	int t; 
    cin >>t;
    while (t --){
        int n, m;
        cin >> n >> m;
        vector<int>* edges = new vector<int>[n];
        for (int i = 0; i < m; i++){
            int f, s;
            cin >> f>> s;
            edges[f - 1].push_back(s - 1);
            edges[s - 1].push_back(f - 1);
        }
        int ans = findLevel(edges, n, 0, n - 1);
        cout<<ans<<endl;
    }
	return 0;
}

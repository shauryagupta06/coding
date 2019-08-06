//When one domino falls, it knocks down the next one, 
//which knocks down the one after that, all the way down 
//the line.
//However, sometimes a domino fails to knock the next one 
//down. In that case, we have to knock it down by hand 
//to get the dominos falling again.
//Your task is to determine, given the layout of some 
//domino tiles, the minimum number of dominos that must 
//be knocked down by hand in order for all of the dominos 
//to fall.

//In KusoRaju's Algo, we keep a stack, call dfs 
//as for disconnected components, and get all nodes
//visited : Find strongly connected components

//The stack obtained contains component nodes whose
//component has minimum ways to reach in and maximum ways 
//to go out, at the top of stack

//For dominos question, we obtain the stack in the same manner
//and the call normal dfs on the stack on the original
//graph only: This gives us min no. of components which
//are not connected
//For every call we increase k, and get the answer k 

//Perform dfs for directed graph, which may be disconnected
#include<bits/stdc++.h>
using namespace std;
stack<int> s;
void dfs(vector<int>* edges, int n, int sv, bool* visited){
    visited[sv] = true;
    for (int i = 0; i < edges[sv].size(); i++){
        int nb = edges[sv][i];
        if (!visited[nb]){
            dfs(edges, n, nb, visited);
        }
    }
    s.push(sv);
}

void dfs_normal(vector<int>* edges, int n, int sv, bool* visited){
    visited[sv] = true;
    for (int i = 0; i < edges[sv].size(); i++){
        int nb = edges[sv][i];
        if (!visited[nb]){
            dfs_normal(edges, n, nb, visited);
        }
    }
}
int main()
{
	int t ; cin >> t;
    while (t -- ){
        int n, m;
        cin >> n >> m;
        vector<int>* edges = new vector<int>[n];
        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
        }
        int k = 0;
        bool* visited = new bool[n];
        for (int i = 0; i < n ; i++){
            visited[i] = false;
        }
        for (int i = 0; i < n ; i++){
            if (!visited[i]){
                dfs(edges, n, i, visited);
            }
        }
        for (int i = 0; i < n ; i++){
            visited[i] = false;
        }
        while (!s.empty()){
            int t = s.top();
            s.pop();
            if (!visited[t]){
                dfs_normal(edges, n, t, visited);
                k++;
            }
        }
        
        cout<<k<<endl;
    }
	return 0;
}




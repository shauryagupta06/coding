//There are N cities in Flatland connected with M 
//unidirectional roads. The cities are numbered from 1 to N. 
//set up a new capital city for his kingdom. For security 
//reasons, the capital must be reachable from all other 
//cities of Flatland.Find list of all candidate cities. 

//Basically, we have to find nodes to which all other nodes 
//are reachable i.e. a set s1,s2..sk such that all n nodes
//are reachacle to s1, to s2 , ..to sk
//This set will be a SCC to which all other SCCs are reachable
//To divide into SCC, while foll. Kusorajus algo,
//we will maintain an array cn for cycle number and
//allot each SCC a cycle number in order of their 
//discovery from the stack

//We will maintain an array out for no. of 
//outdegrees from each connected comp i.e. cycle
//Now we will traverse the entire original graph
//and will increase the count of out[cn] if an edge
//is going to another SCC, i.e. cycle no. not equal

//For the out array, we will find the cnt = no. of cycles
//for which outdegree is 0, cnt = 0 not possible, otherwise
//there will be a cycle b/w SCCs which falsifies the condition 
//for SCCs
//cnt = 1, find the cycle no for which outdegree is 0
//the nodes of this cn will be our ans <s1,s2, ..sk>
//if cnt > 1, there is no such SCC to which all other
//SCCs are reachable, print 0

//This code gave Runtime error until edges and edges max 
//was globally declared

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define max (ll)1e6 + 10
stack<ll> s;
ll out[max];
vector<ll> ans, edges[max], edgesin[max];
ll cn[max];
bool visited[max];
bool visited1[max];
void dfs(vector<ll>* edges, ll n, ll sv, bool* visited){
    visited[sv] = true;
    for (ll i = 0; i < edges[sv].size(); i++){
        ll nb = edges[sv][i];
        if (!visited[nb]){
            dfs(edges, n, nb, visited);
        }
    }
    s.push(sv);
}

void dfs_normal(vector<ll>* edges, ll n, ll sv, bool* visited, ll cycle){
    visited[sv] = true;
    cn[sv] = cycle;
    for (ll i = 0; i < edges[sv].size(); i++){
        ll nb = edges[sv][i];
        if (!visited[nb]){
            dfs_normal(edges, n, nb, visited, cycle);
        }
    }
}
int main()
{
    ll n, m;
    cin >> n >> m;

    for (ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        edges[x - 1].push_back(y - 1);
        edgesin[y - 1].push_back(x - 1);
    }
    memset(visited,0,sizeof(visited));
    for (ll i = 0; i < n ; i++){
        if (!visited[i]){
            dfs(edges, n, i, visited);
        }
    }
    memset(visited1,0,sizeof(visited1));
    ll cycle = 0;
    while (!s.empty()){
        ll t = s.top();
        s.pop();
        if (!visited1[t]){
            dfs_normal(edgesin, n, t, visited1, cycle);
            cycle++;
        }
    }

    for (ll i = 0; i < n ; i++){
        for (ll j = 0; j < edges[i].size(); j++){
            ll nb = edges[i][j];
            if (cn[i] != cn[nb]){
                out[cn[i]]++;
            }
        }
    }
    ll cnt = 0;
    for (ll i = 0; i < cycle; i++){
        if (out[i] == 0){
            cnt++;
        }
    }
    if (cnt > 1){
        cout<<0<<endl;
    }
    else{
        for (ll i = 0; i < n; i++){
            if (out[cn[i]] == 0){
                ans.push_back(i);
            }
        }
        cout<<ans.size()<<endl;
        for (ll i = 0; i < ans.size(); i++){
            cout<<ans[i] + 1<<" ";
        }
        cout<<endl;
    }
    return 0;
}







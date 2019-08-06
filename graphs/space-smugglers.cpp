//Star system is represented by  n planets and m space 
//tunnels between them. Space tunnel is one-way wormhole 
//to travel from one planet to another, requiring an amount 
//of gravitonium to perform the gravity jump. There may be 
//several space tunnels between two planets, but no space 
//tunnel leads to the same planet it starts from.(no self loops)

//Your task as a first officer is to find the minimum 
//amount of gravitonium to travel from the base planet 
//to Ariel, visiting some other planet to store the 
//earnings, and return back to base, picking up the 
//earnings on the way back.

// to save all the "honest" earnings of the previous 
//adventures, he decided to store them on one of the 
//planets on the way to the border.
//Note, that storing the earnings in a base planet
//or the planet, where the job is taking place, 
//is not allowed. But it's allowed to visit Ariel with 
//the earnings as long as you are not doing a job on this 
//planet.

//Basically we need to pick one planet out x of n, where 
//x should not be s(base planet) and also not t(Ariel)
//Find shortest path from base to all planets, from all planets 
//to Ariel, from Ariel to all planets and from all planets 
// to base planets
//Choose a planet x if sum of all the above distances is min
//for x, among all planets
//For inverse tasks, i.e. all to Ariel and all to base,
//we will have an inverse graph with all edges inverse
//Then we will apply Dijkstras four times

//One of the test cases, give TLE, using priority queue
//may improve the complexity

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mp make_pair
#define ll long long int
#define INF 1000000000

void dijkstra(vector<pii>* e, int n, int sv, bool* visited, ll* dist){
    for (int i = 0; i < n; i++){
        dist[i] = INF;
        visited[i] =  false;
    }
    dist[sv] = 0;
    for (int i = 0; i < n - 1; i++){
        int min_dist = INF;
        int curr;
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                if (dist[i] < min_dist){
                    min_dist = dist[i];
                    curr = i;
                }
            }
        }
        
        visited[curr] = true;
        
        for (int i = 0; i < e[curr].size(); i++){
            pii pp = e[curr][i];
            int nb = pp.first;
            int wt = pp.second;
            if (!visited[nb]){
                if (dist[curr] + wt < dist[nb]){
                    dist[nb] = dist[curr] + wt;
                }
            }
        }
    }
    return;
}
int main()
{
	int n, m , s , t;
    cin >> n >> m >> s >> t;
    vector<pii>* edges = new vector<pii>[n];
    vector<pii>* edgesInv = new vector<pii>[n];
    
    for(int i = 0; i < m; i ++){
        int from, to, wt;
        cin >> from >> to >> wt;
        edges[from - 1].push_back(mp(to - 1, wt));
        edgesInv[to - 1].push_back(mp(from - 1, wt));
    }
    
    ll* dist1 = new ll[n];
    ll* dist2 = new ll[n];
    ll* dist3 = new ll[n];
    ll* dist4 = new ll[n];
    bool* visited = new bool[n];
   
    dijkstra(edges, n, s - 1, visited, dist1);
    dijkstra(edgesInv, n, s - 1, visited, dist2);
    dijkstra(edges, n, t - 1, visited, dist3);
    dijkstra(edgesInv, n, t - 1, visited, dist4);
    
    ll ans = INF;
    for (int i = 0; i < n; i++){
        if (i != (s - 1) && i != (t - 1) && dist1[i] != INF && dist2[i] != INF && dist3[i] != INF && dist4[i] != INF ){
            ans = min( ans, dist1[i] + dist2[i] + dist3[i] + dist4[i]);
        }
    }
    if (ans != INF){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
	return 0;
}
//Used priority queue + adjacency list, 
//(V + E)logV complexity of dijkstra
//gives no TLE

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define mp make_pair
#define ll long long int
#define INF 1000000000

void dijkstra(vector<pii>* e, int n, int sv, ll* dist){
    for (int i = 0; i < n; i++){
        dist[i] = INF;
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[sv] = 0;
    pq.push(mp(0, sv));
    while (!pq.empty()){
        pii p = pq.top();
        pq.pop();
        ll d = p.first;
        ll curr = p.second;
        for (ll i = 0; i < e[curr].size(); i++){
            pii pp = e[curr][i];
            ll nb = pp.first;
            ll wt = pp.second;
            if (dist[curr] + wt < dist[nb]){
                dist[nb] = dist[curr] + wt;
                pq.push(mp(dist[nb], nb));
            }
        }
    }
    
    return;
}
int main()
{
	int n, m , s , t;
    cin >> n >> m >> s >> t;
    vector<pii>* edges = new vector<pii>[n];
    vector<pii>* edgesInv = new vector<pii>[n];
    
    for(int i = 0; i < m; i ++){
        int from, to, wt;
        cin >> from >> to >> wt;
        edges[from - 1].push_back(mp(to - 1, wt));
        edgesInv[to - 1].push_back(mp(from - 1, wt));
    }
    
    ll* dist1 = new ll[n];
    ll* dist2 = new ll[n];
    ll* dist3 = new ll[n];
    ll* dist4 = new ll[n];
    bool* visited = new bool[n];
   
    dijkstra(edges, n, s - 1, dist1);
    dijkstra(edgesInv, n, s - 1, dist2);
    dijkstra(edges, n, t - 1, dist3);
    dijkstra(edgesInv, n, t - 1, dist4);
    
    ll ans = INF;
    for (int i = 0; i < n; i++){
        if (i != (s - 1) && i != (t - 1) && dist1[i] != INF && dist2[i] != INF && dist3[i] != INF && dist4[i] != INF ){
            ans = min( ans, dist1[i] + dist2[i] + dist3[i] + dist4[i]);
        }
    }
    if (ans != INF){
        cout << ans << endl;
    }
    else{
        cout << -1 << endl;
    }
	return 0;
}




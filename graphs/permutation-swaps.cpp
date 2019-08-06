//Kevin has a permutation P of N integers 1, 2, ..., N, 
//but he doesn't like it. Kevin wants to get a permutation Q.

//Also he believes that there are M good pairs of 
//integers (ai , bi). Kevin can perform following 
//operation with his permutation:
//Swap Px and Py only if (x, y) is a good pair.
//Help him and tell if Kevin can obtain permutation Q 
//using such operations.

//eg. n = 4 m = 1
//P = 1 3 2 4
//Q = 1 4 2 3
//e1 = 3 4 
//ans: NO

//eg. n = 4 m = 1
//P = 1 3 2 4
//Q = 1 4 2 3
//e1 = 2 4 
//ans: YES

//We make a graph of all good pair indices, we find set of
//connected components of this graph stored in output

//Using connected components, we can say that within one 
//connected component any number can be exchanged with any 
//other no. but if two numbers lie in diff connected components
//they can never be swapped

//DFS Approach
//for each connected component comp, 
//we will make a set per_p which will contain
//numbers at p[i] where i is a part of comp  
//Then we will check if per_p matches with all nos. at
//q[i], order doesn't matter, if there is a mismatch,
//raise flag and break
//then ans: NO, else ans: YES

#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>* edges, unordered_set<int>* comp, bool* visited, int sv){
    visited[sv] = true;
    comp->insert(sv);
    for (int i = 0; i < edges[sv].size(); i++){
        int nb = edges[sv][i];
        if (!visited[nb]){
            DFS(edges, comp, visited, nb);
        }
    }
    return;
}
unordered_set<unordered_set<int>*>* getComponents(vector<int>* edges, int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
    for (int i = 0; i < n ; i++){
        if (!visited[i]){
            unordered_set<int>* comp = new unordered_set<int>();
            DFS(edges, comp, visited, i);
            output->insert(comp);
        }
    }
    return output;
}
int main()
{
	int t; cin >> t;
    while(t -- ){
        int n, m;
        cin >> n >> m;
        int* p = new int[n];
        int* q = new int[n];
        for (int i = 0; i < n; i++){
            cin >> p[i];
        }
        for (int i = 0; i < n; i++){
            cin >> q[i];
        }
        vector<int>* edges = new vector<int>[n];
        for (int i = 0; i < m; i++){
            int f, s;
            cin>> f >> s;
            edges[f - 1].push_back(s - 1);
            edges[s - 1].push_back(f - 1);
        }
        unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
        output = getComponents(edges, n);
        unordered_set<unordered_set<int>*>::iterator it1 = output->begin();
        int flag = 0;
        while (it1 != output->end()){
            unordered_set<int>* comp = *it1;
            unordered_set<int>:: iterator it2 = comp->begin();
            unordered_set<int>* per_p = new unordered_set<int>();
            while (it2 != comp->end()){
                per_p->insert(p[*it2]);
                it2++;
            }
            it2 = comp->begin();
            while (it2 != comp->end()){
                if (per_p->count(q[*it2]) == 0){
                    flag = 1;
                    break;
                }
                it2++;
            }
            if (flag == 1)
                break;
            it1++;
        }
        if (!flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}
//BFS-Approach, shorter code, queue q of BFS maintained
//as vector, so that no deletions done, a starting
//point st maintained as front of queue, which
//moves forward after every iteration
//q can be seen as empty when st >= q.size()
//after each while loop, q acts as vector of 
//connected components after every use

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n, m;
    cin >> n >> m;
    int* P = new int[n];
    int* Q = new int[n];
    for (int i = 0; i < n; i++){
        cin>>P[i];
    }
    for (int i = 0; i < n; i++){
        cin>>Q[i];
    }
    vector<int>* edges = new vector<int>[n];
    for (int i = 0; i < m ; i++){
        int f, s;
        cin>> f >> s;
        edges[f - 1].push_back(s - 1);
        edges[s - 1].push_back(f - 1);
    }
    
    bool* visited = new bool[n];
    for (int i = 0 ; i < n; i++){
        visited[i] = false;
    }
    for (int i = 0; i < n; i++){
        if (visited[i]){
            continue;
        }
        //vextor is maintained, no deletions, so that q can be
        //used later and does not become empty
        //It works as combination of vector comp and queue q: refer bfs-disconnected.cpp
        vector<int> q;
        //st is the starting point of vector which acts as the front of q
        int st = 0; 
        q.push_back(i); 
        visited[i] = true;

        while (st < q.size()){
            //equivalent to extracting fron and popping queue
            int f = q[st];
            st++;
            for (int j = 0; j < edges[f].size(); j++){
                int nb = edges[f][j];
                if (!visited[nb]){
                    q.push_back(nb);
                    visited[nb] = true;
                }
            }
        }
        //one connected component is ready in vector q
        vector<int> perm1;
        vector<int> perm2;
        for (int i = 0; i < q.size(); i++){
            perm1.push_back(P[q[i]]);
            perm2.push_back(Q[q[i]]);
        }
        sort(perm1.begin(), perm1.end());
        sort(perm2.begin(), perm2.end());
        for (int i = 0; i < perm1.size(); i++){
            if (perm1[i] != perm2[i]){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}
int main()
{
	int t; cin >> t;
    while (t -- ){
        solve();
    }
	return 0;
}

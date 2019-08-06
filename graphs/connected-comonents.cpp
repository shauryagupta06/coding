//Here adjacency list is used, which is maintained through 
//an array of vectors, array size is fixed = no. of vertices
//here we take nos. from 1 instead of 0, but store them
//corresponding to 0 indexing by doing v - 1
//Adjacency list takes less traversal time as it only explores
//neighboring edges , bringing complexity down from V^2 to E

//Output is a pointer to a set of pointers to set, declared as:
//unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>()
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
        while (it1 != output->end()){
            unordered_set<int>* comp = *it1;
            unordered_set<int>:: iterator it2 = comp->begin();
            while (it2 != comp->end()){
                cout<<*it2 + 1<<" ";
                it2++;
            }
            cout<<endl;
            delete comp;
            it1++;
        }
        delete output;
    }
	return 0;
}


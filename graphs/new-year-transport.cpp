//Given n cells in a world from 1 to n
//He thought of n - 1 positive integers a1, a2, ..., an - 1. 
//For every integer i where 1 ≤ i ≤ n - 1 
//the condition 1 ≤ ai ≤ n - i holds. 

//Next, he made n - 1 portals, numbered by integers 
//from 1 to n - 1. The i-th (1 ≤ i ≤ n - 1) portal 
//connects cell i and cell (i + ai), and one can travel 
//from cell i to cell (i + ai) using the i-th portal. 
//Unfortunately, one cannot use the portal backwards, 
//which means one cannot move from cell (i + ai) to cell 
//i using the i-th portal. It is easy to see that because
//of condition 1 ≤ ai ≤ n - i one can't leave the World 
//using portals.

//I am standing at cell 1, and I want to go to cell t. 
//determine whether I can go to cell t by only using 
//the construted transportation system.

//eg. n = 8 , t = 4
//arr = 1 2 1 2 1 2 1
//ans: YES
//the visited cells are: 1, 2, 4; so we can successfully 
//visit the cell 4.

//eg. 8 5 
//1 2 1 2 1 1 1
//ans: NO
//In the second sample, the possible cells to visit are: 
//1, 2, 4, 6, 7, 8; so we can't visit the cell 5 from 1
//in any path, which we want to visit.

//Normal solution: check for 0, update i as i + arr[i],
//check for updated i, if anywhere t is found,print yes
//loop finishes or we reach a higher i that t(there's no
//going back): print NO

using namespace std;
int main()
{
	int n; int t;
    cin >> n >> t;
    int* arr = new int[n - 1];
    for (int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; ){
        i = i + arr[i];
        if (i == (t - 1)){
            cout << "YES" << endl;
            break;
        }
        if (i > (t - 1)){
            break;
        }
    }
    cout << "NO" << endl;
	return 0;
}

//Connected components: DFS Approach
//A unidirectional paths will be formed
//directed graph
//One dfs call will mark all vertices true
//which can be reached through unidirectional paths
//starting from sv

#include<vector>
#include<iostream>
using namespace std;
void dfs(vector<int>* edges, int sv, bool* visited){
    visited[sv] = true;
    int nb = edges[sv][0];
    if (!visited[nb]){
        dfs(edges, nb, visited);
    }
    return;
}
int main()
{
	int n; int t;
    cin >> n >> t;
    int* arr = new int[n];
    for (int i = 0; i < n - 1; i++){
        cin >> arr[i];
    }
    arr[n - 1] = 0;
    vector<int> *edges = new vector<int>[n];
    for (int i = 0; i < n; i++){
        edges[i].push_back(i + arr[i]);
    }
    bool* visited = new bool[n];
    for (int i = 0; i < n ; i++){
        visited[i] = false;
    }
    dfs(edges, 0, visited);
    if (visited[t - 1])
        cout << "YES"<<endl;
    else
    {
        cout << "NO"<<endl;
    }
    

    return 0;
}
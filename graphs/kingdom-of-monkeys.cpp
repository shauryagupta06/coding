//You all have to make teams of N monkeys and they will
//go on a hunt for Bananas. The team that returns with the 
//highest number of Bananas will be rewarded with as many 
//gold coins as the number of Bananas with them. 
//Given there are N monkeys in the kingdom. 
//Each monkey who wants to team up with another monkey 
//has to perform a ritual. Given total M rituals are performed
//Each ritual teams up two monkeys. If Monkeys A and B 
//teamed up and Monkeys B and C teamed up, then Monkeys 
//A and C are also in the same team.

//You are given an array A where Ai is the number of 
//bananas i'th monkey gathers.

//Find out the number of bananas obtained by the team which gets
//the maximum number of bananas. i.e. no. of gold coins
//to be given

//eg. n = 4, m = 3
//1 2
//2 3
//3 1
//a = 1 2 3 5
//ans = 6
//Monkeys 1,2 ,3 are in the same team. They gather 1+2+3=6 
//bananas.
//Monkey 4 is a team. It gathers 5 bananas.
//Therefore, number of gold coins (highest number of 
//bananas by a team) = 6.

//Connected component problem, bfs approach
//for each connected component, calc the sum of bananas
//among the sums of different connected components, 
//ans is tha maximum one, print it

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll bfs(vector<int>* edges, int n, int sv, ll* arr, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    ll sum = arr[sv];
    while (!q.empty()){
        int f = q.front();
        q.pop();
        for (int i = 0; i < edges[f].size(); i++){
            int nb = edges[f][i];
            if (!visited[nb]){
                q.push(nb);
                visited[nb] = true;
                sum += arr[nb];
            }
        }
    }
    return sum;
}
void solve(vector<int>* edges, int n, ll* arr){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    ll max_ans = INT_MIN;
    for (int i = 0; i < n ; i++){
        if (!visited[i]){
            ll ans = bfs(edges, n, i, arr, visited);
            if (ans > max_ans)
                max_ans = ans;
        }
    }
    cout << max_ans << endl;
}
int main()
{
	int t; cin >> t;
    while (t --){
        int n, m;
        cin >> n >> m;
        vector<int>* edges = new vector<int>[n];
        for (int i = 0; i < m; i ++){
            int f, s;
            cin>> f >> s;
            edges[f - 1].push_back(s - 1);
            edges[s - 1].push_back(f - 1);
        }
        ll* arr = new ll[n];
        for (int i = 0; i < n; i++){
            cin>>arr[i];
        }
        solve(edges, n, arr);
    }
	return 0;
}


//Kruskal algo for getting edges of Minimum Spanning Tree
//in output array
//Arrage input in ascending order of weight
//Pick an edge, check for cycle,
//if adding the curr edge introduces cycle, skip it
//If not, add it to output, increase count, make parent same
//We should stop once count reaches v - 1 = no. of edges in MST

//Cycle detection:

//HasPath can be used to detect cycle: Before adding any edge,
//check if v1, v2 have a path b/w them
//if yes, then skip current edge
//else, add it to output, inccrease count
//O(V + E) time => O(V +V^2) worst case

//Union - find can be used to detect cycle:
//Maintain a parents array for every vertex, 
//Pick an edge from input, check parents of v1 and v2
//If same, means they lie in a connected component, 
//do not add the edge 
//else, add curr edge to output, increase count
//For two parents p1, p2, make p2 parent of p1 or vice-versa
//O(V) =  Worst case when union-find tree is skewed

//Kruskal complexity = O(ElogE + EV)
//ElogE for sorting, V for cycle detection
//in worst case , all edges may be reqired to check for cycle
//so E*V 

#include <iostream>
#include <algorithm>
using namespace std;
class Edge {
    public:
    int v1;
    int v2;
    int w;
    
    //Parameterized constructor
    Edge(int v1, int v2, int w){
        this -> v1 = v1;
        this -> v2 = v2;
        this -> w = w;
    }
    //Default is needed for declaring arrays of type Edge class
    Edge(){
        
    }
};
//Comparator func to sort Edge type array by w in ascending order
bool ourComparator(Edge a, Edge b){
    return (a.w < b.w);
}

Edge* MSTKruskal(Edge* input, int V, int E){
    Edge *output = new Edge[V - 1];
    int parent[V];
    
    //Every vertex will become its own parent
    for (int i = 0; i < V; i++){
        parent[i] = i;
    }
    int count = 0;
    int i = 0;
    
    //count increases only when a new edge is added to output
    //i increases everytime: picks next edge from input
    while (count < V - 1 ){
        int curr_v1 = input[i].v1;
        int curr_v2 = input[i].v2;
        int curr_w = input[i].w;
        
        int y = curr_v1;
        while (y != parent[y]){
            y = parent[y];
        }
        int p_v1 = y;
        
        y = curr_v2;
        while (y != parent[y]){
            y = parent[y];
        }
        int p_v2 = y;
        
        //If Parents of v1 and v2 of current edge are different, means they lie
        //in different connected components
        //Add curr edge to output, increase count and make one parent, the parent of 
        //other parent
        if (p_v1 != p_v2){
            output[count] = input[i];
            count++;
            parent[p_v1] = p_v2;
        }
        //If parents are same, just continue and increse i, count will not increase
        i++;
    }
    return output;
}
int main()
{
    int V, E;
    cin >> V >> E;
    Edge *input = new Edge[E];
    for (int i = 0; i < E; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        Edge e(v1, v2, w);
        input[i] = e;
    }
    sort(input, input + E, ourComparator);
    Edge *output = new Edge[V - 1];
    output = MSTKruskal(input, V, E);

    for (int i = 0; i < V - 1; i++){
        int s = (output[i].v1 <= output[i].v2)?output[i].v1:output[i].v2;
        int l = (output[i].v1 + output[i].v2) - s;
        cout<<s<<" "<<l<<" "<<output[i].w<<endl;
    }
    return 0;
}
//Union rank and path compression



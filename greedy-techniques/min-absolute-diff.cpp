/*Given an integer array A of size N, find and return the 
minimum absolute difference between any two elements in the 
array.
We define the absolute difference between two elements ai, 
and aj (where i != j ) is |ai - aj|. */

//APPROACH: Greedy, sort the array and find min diff among
//only adjacent pairs
//if we take a subproblem and follow this technique, then also
//solution will be optimal, hence it has an optimal
//substructute and greedy works as no other non -adjacent
//pair vcan have a lesser difference than adjacent pairs
//after sorting
//O(n + nlogn) = O(nlogn)
using namespace std;
int minAbsoluteDiff(int arr[], int n) {

    sort(arr, arr+n);
    int diff = INT_MAX;
    for (int i = 0 ; i < n - 1; i++){
        int d = arr[i + 1] - arr[i];
        if (d < diff){
            diff = d;
        }
    }
    return diff;
}

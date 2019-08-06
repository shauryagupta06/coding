/*Nikunj eats n donuts in one sitting, and each donut has a 
calorie count, ci. After eating a donut with k calories, 
he must walk at least (2^j) x k(where j is the number donuts 
he has already eaten) miles to maintain his weight.
Given the individual calorie counts for each of the n 
donuts, find and print a long integer denoting the minimum 
number of miles Nikunj must walk to maintain his weight. 
Note that he can eat the donuts in any order. */

//APPROACH: Greedy: we need to minimize sum of (2^j) x k
//where j will be 0, 1...n-1 after having every donut
//because it is the no. of donuts Nikunj has eaten before 
//eating ith donut. So to minimize no. of miles, Nikunj 
//should eat donut with highest calorie k first so that 
//lowest value i.e. 2^0 is multiplied with k and hea should
//eat donut with lowest calorie last
//Arrange array in descending order and compute m
//m = k1*(2^0) + k2*(2^1) + k3*(2^3) +...+kn*(2^n-1)
//where k1 is highest calorie and kn is lowest calorie
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n; cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll m = 0;
    sort(arr, arr + n);
    for ( int i = n - 1, k = 0; i>= 0 && k < n; i--, k++){
        m += pow(2,k)*arr[i];
    }
    cout << m << endl;
    return 0;
}
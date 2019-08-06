//Given an array A of size N having distinct elements, 
//the task is to find the next greater element for each 
//element of the array in order of their appearance in 
//the array. If no such element exists, output -1 

//use a stack, push 0th element, for i from 1 to n-1 
//keep poppinfg elements till arr[i] > tos and stack
//is non empty, arr[i] will ne the ans for each tos

#include<iostream>
using namespace std;
#define mp make_pair
#include<stack>
#include<bits/stdc++.h>
#define ll long long int 
int main()
 {
	int t; cin >> t;
	while (t--){
	    ll n ;
	    cin >> n;
	    ll* arr = new ll[n];
	    for (ll i = 0; i < n ;i++){
	        cin >> arr[i];
	    }
        ll* ans = new ll[n];
	    stack<pair<ll,ll>> s;
	    s.push(mp(arr[0], 0 ));
	    for (ll i = 1; i < n; i++){
	        if (s.empty()){
	            s.push(mp(arr[i], i));
	            continue;
	        }

            
	        while (!s.empty() && s.top().first < arr[i]){
	            pair<ll,ll> pp = s.top();
	            ans[pp.second] = arr[i];
	            s.pop();
	        }
	        
	        s.push(mp(arr[i],i));
	    }	
	    while (!s.empty()){
	        pair<ll,ll> pp1 = s.top();
	        ans[pp1.second] = -1;
	        s.pop();
	    }
	    for (ll i = 0; i < n; i++){
	        cout << ans[i] << " ";
	    }
	    cout<<endl;
	}
	return 0;
}
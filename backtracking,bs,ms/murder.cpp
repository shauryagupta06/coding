//Given numbers in array on stairs
//for each number on the stairs he will note down 
//the sum of all the numbers previously seen on the 
//stairs which are smaller than the present number. 
//Calculate the sum of all the numbers 
//written on his notes diary.

//eg. 1 5 3 6 4
//ans: 15
//explanation: For the first number: 1, 
//the contribution to the sum is 0.(nothing on left)
//For 5, the contribution to the sum is 1.
//For 3, the contribution to the sum is 1.
//For 6, the contribution to the sum is 9 = (1+5+3).
//For 4r, the contribution to the sum is 4 (1+3).
//Hence the sum is 15 (0+1+1+9+4).

//APPROACH1: Brute Force: Iterate through array, for elements
//before array , add to sum if less than curr element
//Time : O(n^2)

//APPROACH2: Merge sort extenstion
//eg 1 5 3 6 4, two parts: 1 5 3 | 6 4
//for 1st part, sorted: 1 3 5 , ans1 = 1 + 1 = 2
//for 2nd part, sorted: 4 6, ans2 = 0
//merging , if l1[i] < l2[j], sum += l1[i] * (n2 - j)
//for merge, sum = 1*(2 - 0) +  3*(2 - 0) +  5*(2 - 1)
//ans3 = 2 + 6 + 5 = 13
//final ans = ans1 + ans2 + ans3 = 2 + 0 + 13 = 15
//O(nlogn) time 

#include<iostream>
#define ll long long int 
using namespace std;
ll merge(ll* arr, ll l, ll m, ll h){
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 = h - m;
    ll L1[n1];
    ll L2[n2];
    ll sum = 0;
    for (i = 0; i < n1; i++){
        L1[i] = arr[i + l];
    }
    for (i = 0; i < n2; i++){
        L2[i] = arr[i + m + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L1[i] < L2[j]){
            arr[k] = L1[i];
            sum += L1[i]*(n2 - j);
            k++;
            i++;
        }
        else{
            arr[k] = L2[j];
            k++;
            j++;
        }
    }
    while (i < n1){
        arr[k] = L1[i];
        k++;
        i++;
    }
    while (j < n2){
        arr[k] = L2[j];
        k++;
        j++;
    }
    return sum;
}
ll mergeSort(ll* arr, ll l, ll h){
    ll sum = 0;
    if (l < h){
        ll m = (l + h)/2;
        sum += mergeSort(arr, l, m);
        sum += mergeSort(arr, m + 1, h);
        sum += merge(arr, l, m, h);
    }
    return sum;
}
int main() {
    int t; cin>>t;
    while (t -- ){
        ll n;
        cin>>n;
        ll* arr = new ll[n];
        for(ll i = 0; i < n; i++){
            cin>>arr[i];
        }
        cout<<mergeSort(arr, 0, n - 1)<<endl;
    }
}
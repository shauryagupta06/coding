//Given array, return count of inversions, i.e. no. of pairs
//which are incorrectly placed w.r.t. ascending order

//APPROACH1: Brute Force: Iterate through array, for elements
//after array , add to count if less than curr element
//Time : O(n^2)

//APPROACH2: Merge sort extenstion
//eg 1 5 3 6 4, two parts: 1 5 3 | 6 4
//for 1st part, sorted: 1 3 5 , ans1 = 1 
//for 2nd part, sorted: 4 6, ans2 = 1
//merging , if l1[i] > l2[j], inv +=  (n1 - i)
//for merge, inv = (3 - 2) = 1
//ans3 = 1
//final ans = ans1 + ans2 + ans3 = 3
//O(nlogn) time 

#define ll long long
long long merge(int A[], ll l, ll h, ll m){
    ll size1 = m - l + 1;
    ll size2 = h - m;
    ll i, j, k;
    int L1[size1];
    int L2[size2];
    ll inv = 0;
    for (i = 0; i < size1; i++){
        L1[i] = A[i + l];
    }
    for (i = 0; i < size2; i++){
        L2[i] = A[i + m + 1];
    }
    k = l;
    i = 0, j = 0;
    while (i < size1 && j < size2){
        if (L1[i] <= L2[j]){
            A[k] = L1[i];
            i++;
            k++;
        }
        else{
            A[k] = L2[j];
            inv += size1 - i;
            j++;
            k++;
        }
    }
    while (i < size1){
        A[k] = L1[i];
        i++;
        k++;
    }
    while (j < size2){
        A[k] = L2[j];
        j++;
        k++;
    }
    return inv;
}
long long mergeSort(int A[], ll l, ll h){
    ll inv = 0;
    if (l < h){
        ll m = (l + h) / 2;
        inv = mergeSort(A, l, m);
        inv += mergeSort(A, m + 1, h);
        inv += merge(A, l, h, m);
    
    }
    return inv;
}
long long solve(int A[], int n)
{
    ll nl = (ll)n;
    return mergeSort(A, 0, nl - 1);
}
#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int findMaxLength(int* arr, int n){
    for (int i = n - 1; i >= 0; i--){
        for (int j = i; j < n; j++){
            int si = j - i;
            int ei = j;
            int cnt = 0;
            for (int k = 0; k < 31; k++){
                int b = (arr[si] >> k) & 1;
                for (int l = si + 1; l <= ei; l++){
                    b = b ^ ((arr[l] >> k) & 1);
                }
                if (b == 1){
                    cnt ++;
                }
            }
            if (cnt % 2 == 0){
                return i + 1;
            }
        }
    }
    return 0;
}
int main(){
    int t; cin >>t;
    for (int c = 1; c <= t;c++){
        int n, q;
        cin >> n >> q;
        int* arr = new int[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int* ans = new int[q];
        for (int i = 0; i < q; i++){
            int id, p;
            cin >> id >> p;
            arr[id] = p;
            ans[i] = findMaxLength(arr, n);
        }
        cout <<"Case #"<<c<<": ";
        for (int i = 0; i < q; i++){
            cout << ans[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}
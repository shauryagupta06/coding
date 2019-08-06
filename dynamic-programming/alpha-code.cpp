/* if a denotes 1, b denotes 2... c denotes 3, find no. of codes 
possible for a given integer  */
//eg 2134: bacd, ucd, amd , ans: 3
//To handle zeros, if the code has last digit 0
//then size - 1 call should not be made
//size - 2 call is made only when last two digits
//lie in b/w 10 to 26(inclusive
//If my string has 2 or more than 2 consecutive zeros
//final answer is always 0

//Recursion - O(2^n)
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod (ll)(1e9 + 7)
ll alphaCode(int* arr, int size){
    if (size == 0 || size == 1){
        return 1;
    }
    ll ans = 0;
    if (arr[size -1] != 0){
        ll ans1 = alphaCode(arr, size - 1, output)% mod;
        ans += ans1%mod;
    }

    if (arr[size - 2]*10 + arr[size - 1] <= 26 && arr[size - 2]*10 + arr[size - 1] >= 10){
        ll ans2 = alphaCode(arr, size - 2, output) % mod;
        ans += (ans2%mod);
    }
    return ans%mod;
}
int main()
{
    while (1){
        string s;
        cin >> s;
        if (s[0] == '0'){
            break;
        }
        int *arr = new int[s.size()];
        for (int i = 0; i < s.size(); i++){
            arr[i] = s[i] - '0';
        }
        cout << alphaCode(arr, s.size()) << endl;
    }
    return 0;
}
//Memoization: O(n), n = size of string = no. of unique calls
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod (ll)(1e9 + 7)
ll alphaCode(int* arr, int size, ll* output){
    if (size == 0 || size == 1){
        output[size] = 1;
        return 1;
    }
    if (output[size] != 0){
        return output[size];
    }
    
    ll ans = 0;
    if (arr[size -1] != 0){
        ll ans1 = alphaCode(arr, size - 1, output)% mod;
        ans += ans1%mod;
    }

    if (arr[size - 2]*10 + arr[size - 1] <= 26 && arr[size - 2]*10 + arr[size - 1] >= 10){
        ll ans2 = alphaCode(arr, size - 2, output) % mod;
        ans += (ans2%mod);
    }
    
    output[size] = ans%mod;
    return ans%mod;
}
int main()
{
    while (1){
        string s;
        cin >> s;
        if (s == "0"){
            break;
        }
        int *arr = new int[s.size()];
        for (int i = 0; i < s.size(); i++){
            arr[i] = s[i] - '0';
        }
        ll* output = new ll[s.size() + 1];
        for (int i = 0; i < s.size() + 1; i++){
            output[i] = 0;
        }
        cout << alphaCode(arr, s.size(), output) << endl;
    }
    return 0;
}
//DP - O(n) - Iterative 
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod (ll)(1e9 + 7)
ll alphaCode(int* arr, int size){
    
    ll* output = new ll[size + 1];
    
    for (int i = 0; i < size + 1; i++){
        output[i] = 0;
    }
    output[0] = 1;
    output[1] = 1;
    for (int i = 2; i < size+1 ; i++){
        ll ans = 0;
        if (arr[i - 1] != 0){
            ans += (output[i - 1]%mod);
        }
        if (arr[i - 2]*10 + arr[i - 1] <= 26 && arr[i - 2]*10 + arr[i - 1] >= 10){
            ans += (output[i - 2]%mod);
        }
        if (ans == 0){
            output[size] = 0;
            break;
        }
        else{
            output[i] = ans%mod;
        }
    }
    return output[size];
}
int main()
{
    while (1){
        string s;
        cin >> s;
        if (s == "0"){
            break;
        }
        int *arr = new int[s.size()];
        for (int i = 0; i < s.size(); i++){
            arr[i] = s[i] - '0';
        }

        cout << alphaCode(arr, s.size()) << endl;
    }
    return 0;
}

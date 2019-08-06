/*Once upon time there was a cute princess called Farida 
living in a castle with her father, mother and uncle. On 
the way to the castle there lived many monsters. Each one 
of them had some gold coins. Although they are monsters 
they will not hurt. Instead they will give you the gold
 coins, but if and only if you didn't take any coins from 
 the monster directly before the current one. To marry 
 princess Farida you have to pass all the monsters 
and collect as many coins as possible. Given the number of 
gold coins each monster has, calculate the maximum number 
of coins you can collect on your way to the castle. */

//APPROACH: select max of including and excluding
//inc = self + ans of i-2 (leaving adjacent)
//exc = ans of i -2 
//O(n) time O(n) space

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int t; cin >> t;
    for (int k = 1; k <= t; k++){
        int n; cin >> n;
        ll* arr = new ll[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll* dp = new ll[n];
        dp[0] = arr[0];
        for(int i = 1; i < n; i++){
            ll inc = arr[i];
            if (i - 2 >= 0 ){
                inc += dp[i - 2];
            }
            dp[i] = max(inc, dp[i - 1]);
        }
        cout <<"Case "<<k<<": "<<dp[n - 1]<<endl;
    }
    return 0;
}

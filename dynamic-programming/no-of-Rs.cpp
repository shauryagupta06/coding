/*RK gives you a string S consisting of characters 'R' and 'K'
 only. Now you are allowed to do exactly one move that is you 
 have to choose two indices i and j (1<=i<=j<=|S| where |S| 
 is string length ) and flip all the characters at position 
 X where i<=X<=j. Flipping the character means :
if S[X]='R' :  //If character at position X is 'R' then change
 it to 'K'
  S[X]='K'  
else :          //else if character at position X is 'K' 
then change it to 'R'
  S[X]='R'
Now your goal is that after exactly one move you have to 
obtain the maximum number of R's as RK loves this character
 very much. So help RK with maximum R's.*/

 //APPROACH: First we can count no of Rs = noR and convert all
 //to Rs to -1 and all Ks to 1
 //We need a to find a subarray with max Ks and min Rs, 
 //so we find the max sum subarray by kadane Algo 
 //in the new array of 1s and -1s
 //the max sum will denote the no. of new Rs wich can be 
 //added after flipping, it balances the old R with K i.e
 //-1 + 1 = 0, so ans is maxsum + noR

 //Edge: If there are all Rs in the string, we need to 
 //make exactly 1 move, so we have to flip 1 R and ans
 //will be string size - 1

 #include <bits/stdc++.h>
using namespace std;

int kadane(int* arr, int n){
    int currmax = 0;
    int gmax = 0;
    for (int i = 0; i < n; i++){
        currmax = currmax + arr[i];
        if (currmax > gmax){
            gmax = currmax;
        }
        if (currmax < 0){
            currmax = 0;
        }
    }
    return gmax;
}
int main()
{
    int t; cin >> t;
    while (t --){
        string s; cin >> s;
        int noR = 0;
        int* arr = new int[s.size()];
        for (int i = 0; i < s.size(); i++){
            arr[i] = 0;
        }
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'R'){
                arr[i] = -1;
                noR ++;
            }
            if (s[i] == 'K'){
                arr[i] = 1;
            }
        }
        if (noR == s.size()){
            cout << s.size() - 1 << endl;
        }
        else{
            cout << noR + kadane(arr, s.size())<<endl;
        }
    }
}

#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define SIZE 100000 + 1

int p[SIZE * 2];

string addBoundaries(string& s){
    string s2;
    s2 = "@";
    for (int i = 0; i < s.size(); i++){
        s2 += "#" + s.substr(i,1);
    }
    s2 += "#$";
    return s2;
}
string longestPalinSubs(string& s){
    string s2 = addBoundaries(s); 
    //s2 = @#a#b#c#b#a#b#c#b#$
    //c is the centre of current palindrome
    //r is the right boundary of current palindrome
    int c = 0, r = 0;

    //for each i loop:
    for (int i = 1; i < s2.size() - 1; i++){
        //calculate mirror
        int idash = c - (i - c);

        //if i is contained in current palindrome
        if (r > i){
            //then p[i] can be p[idash] if palindrome
            //around i does not reach the right boundary of 
            //current palindrome
            //if it reaches the right boundary,i.e. p[i] = r-i
            //then it does not extend right boundary
            //because it was favourable, then we would have 
            //expanded already our current palindrome
            p[i] = min( r - i, p[idash]);
        }
        //start looping after p[i], 
        //if p[i] is contained in current palindrome and
        //p[i] = p[idash] , then while loop will not be entered
        //saving the complexity
        while (s2[i + 1 + p[i]] == s2[i - 1 - p[i]]){
            p[i]++;
        }   
        //if the palidrome around i as centre
        //is beyond the right boundary of current palindrome
        //the update centre and its right boundary
        //such that palindrome with centre i becomes new
        //current palindrome
        if (i + p[i] > r){
            c = i;
            r = i + p[i];
        }
    }

    //p = [0 0 1 0 1 0 5 0 1 0 7 0 1 0 3 0 1 0 0]
    //p.length = s2.length
    //eg. p[6] = 5, s2.substr = "#a#b# c #b#a#"
    //s.subsrt for the same = "abcba" (len = 5)

    //select max length with its centre
    //value in p array is half of req. length in s2 and
    //equal to req. length in s
    int mp = 0;
    int ci = 0;
    for (int i = 1; i < s2.size() - 1; i++){
        if (p[i] > mp){
            mp = p[i];
            ci = i;
        }
    }
    cout<<mp<<endl;
    //get index in original string s and length will be p[i].max
    return s.substr((ci - 1 - mp)/2, mp);
}
int main(){
    string s = "abcbabcb";
    cout<<longestPalinSubs(s)<<endl;
    return 0;
}
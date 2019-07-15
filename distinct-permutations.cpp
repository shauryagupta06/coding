#include <bits/stdc++.h>
using namespace std;

int main() {
    string a="DAB";
    
    sort(a.begin(),a.end());
    do{
       cout<<a<<" "; 
    }while(next_permutation(a.begin(),a.end()));
}
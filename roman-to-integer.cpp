#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int romanToInteger(string roman){
    map<char,int> rmap;
    rmap['I'] = 1;
    rmap['V'] = 5;
    rmap['X'] = 10;
    rmap['L'] = 50;
    rmap['C'] = 100;
    rmap['D'] = 500;
    rmap['M'] = 1000;
    
    int i=0;
    int number=0;
    if (roman.size() <= 1){
        return rmap[roman[0]];
    }
    
    while (i<roman.size()) {
        
        if (rmap[roman[i]] < rmap[roman[i+1]]){
            number += rmap[roman[i+1]] - rmap[roman[i]];
            i += 2;
        }
        else {
            number += rmap[roman[i]];
            i++;
        }
    }
    return number;
}
int main() {
	int t;cin>>t;
	while(t--){
	    string roman;
	    cin>>roman;
	    cout<<romanToInteger(roman)<<endl;
	}
	return 0;
}
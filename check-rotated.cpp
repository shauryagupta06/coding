#include <iostream>
using namespace std;

//rotated by two places or not
//eg. a = amazon, b= azonam
//check for anticlock OR clock, antics = azonam, clocks = onamaz
//O(n) time 

bool checkRotated(string a, string b){
    string antics;
    string clocks;
    if (a.size() != b.size())
        return false;
        
    antics = a.substr(2,a.size()-2) + a.substr(0,2);
    clocks = a.substr(a.size()-2,2) + a.substr(0,a.size()-2);
    
    if (antics == b || clocks == b)
        return true;
    return false;
}
int main() {
	int t;cin>>t;
	while(t--){
	    string a,b;
	    cin>>a>>b;
	    if (checkRotated(a,b))
	        cout<<1<<endl;
	    else
	        cout<<0<<endl;
	}
	return 0;
}
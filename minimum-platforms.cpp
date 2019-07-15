#include <iostream>
using namespace std;
#include <map>

int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int *arr = new int[n];
	    int *dep = new int[n];
	    for (int i=0;i<n;i++)
	        cin>>arr[i];
	    for (int i=0;i<n;i++)
	        cin>>dep[i];
	    multimap <int,char> ad;
	    for (int i=0;i<n;i++)
	        ad.insert(pair <int,char> (arr[i],'a'));
	    for (int i=0;i<n;i++)
	        ad.insert(pair <int,char> (dep[i],'d'));
	    int count = 0;
	    int gcount = 0;
	    multimap <int,char> :: iterator itr;
	    /*for (itr = ad.begin(); itr != ad.end(); ++itr) 
    { 
        cout  <<  '\t' << itr->first 
              <<  '\t' << itr->second << '\n'; 
    } */
    
	    for (itr = ad.begin();itr!= ad.end();++itr){
	        
	        if (itr->second == 'a')
	            count ++;
	        else 
	            count --;
	        gcount = max(gcount,count);
	    }
	    cout<<gcount<<endl;
	}
	return 0;
}
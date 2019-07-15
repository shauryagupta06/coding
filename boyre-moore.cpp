#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for (int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int maj,count;
	    maj =0;
	    count = 1;
	    
	    for (int i=1;i<n;i++){
	        if (count==0){
	            maj = i;
	            count = 1;
	        }
	        else if (v[maj]==v[i]) count++;
	        else count--;
	    }
	    
	    count = 0;
	    for (int i=0;i<n;i++){
	        if (v[i]==v[maj]) count++;
	    }
	    
	    if (count>(n/2))
	    cout<<v[maj]<<endl;
	    else
	    cout<<-1<<endl;
	}
	return 0;
}
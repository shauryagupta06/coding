#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int> v(n);
	    vector<int> m;
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int max = v[n-1];
	    m.push_back(max);

	    for (int i=n-2;i>=0;i--){
	        if (v[i]>=max){
	            max=v[i];
	            m.push_back(max);
	        }
	    }

	    for (int i=m.size()-1;i>=0;i--){
	        cout<<m[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
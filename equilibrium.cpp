#include <iostream>
#include <vector>
using namespace std;
int equi(vector<int> v, int n){
    int sum=0;
    int leftsum = 0;
    for(int i=0;i<n;i++){
	        sum+=v[i];
	}
	for(int i=0;i<n;i++){
	    sum -= v[i];
	    if (leftsum==sum)
	        return i;
	    leftsum += v[i];
	}
    return -1;
}
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int ans = equi(v,n);
	    if (ans!=-1)
	    cout<<ans+1<<endl;
	    else
	    cout<<ans<<endl;
	}
	return 0;
}
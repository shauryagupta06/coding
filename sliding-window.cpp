#include <iostream>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--){
	    int n,s;
	    cin>>n>>s;
	    int* a = new int[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    int st = 0;
	    int end = 0;
	    int sum = 0;
	    bool found = false;
	    sum = sum + a[end];
	    while (end<n){
	        if (sum==s){
	            cout<<st+1<<" "<<end+1<<endl;
	            found = true;
	            break;
	        }
	        else if (sum<s)
	            sum += a[++ end];
	        else
	            sum -= a[st ++];
	    }
	    if (found == false)
	        cout<<-1<<endl;
	}
	return 0;
}
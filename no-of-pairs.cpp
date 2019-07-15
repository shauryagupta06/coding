#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main() {
	int t;cin>>t;
	while(t--){
	    int nx,ny;
	    cin>>nx>>ny;
	    vector<int> vx;
	    vector<int> vy;
	    for (int i=0;i<nx;i++){
	        int a;cin>>a;
	        vx.push_back(a);
	    }
	    for (int i=0;i<ny;i++){
	        int a;cin>>a;
	        vy.push_back(a);
	    }
	    sort(vy.begin(),vy.end());
	    sort(vx.begin(),vx.end());
	    
	    int count = 0;
	    int k=0;
	    while (k < nx){

	        if (vx[k] == 1){
	            int j=0;
	            while (j<ny){
	                if (vy[j] == 0){
	                    count++;
	                }
	                else 
	                    break;
	                j++;
	            }
	        }
	        
	        else if (vx[k] == 2){
	            int j = 0;
	            while (vy[j] <= 4)
	                j++;
	            if (j < ny)
	                count += (ny - j);
	        }
	        
	        else if (vx[k] == 3){
	            int j1 = 0;
	            while (j1<ny){
	                if (vy[j1] == 2){
	                    count++;
	                }
	                else if (vy[j1] > 2)
	                    break;
	                j1++;
	            }
	            int j2 = 0;
	            while (vy[j2 <= 3])
	                j2++;
	            if (j2 < ny)
	                count += (ny - j2);
	            
	        }
	        else if (vx[k] != 0){
	            int j=0;
	            while (vy[j] <= vx[k])
	                j++;
	            if (j < ny)
	                count += (ny - j);
	        }
	        k++;
	    }
	    int counto = 0;
	    int j = 0;
	    while (j < ny){
	       if (vy[j] == 1){
	           counto++;
	       }
	       else if (vy[j] > 1)
	            break;
	       j++;
	    }
	    
	    int l = 0;
	    while (vx[l] <= 1)
	        l++;
	    int total = (nx - l)*counto;
	    count += total;
	    cout<<count<<endl;
	}
	return 0;
}
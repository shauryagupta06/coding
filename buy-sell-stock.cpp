#include <iostream>
using namespace std;

class Interval{
    public:
        int buy;
        int sell;
};
void buysell(int price[],int n){
    if (n==1){
        cout<<"No Profit"<<endl;
        return;
    }
    
    int count = 0;
    
    Interval v[(n/2)+1];
    
    int i = 0;
    while(i<n-1){
        
        while((i<n-1) && (price[i]>=price[i+1])){
            i++;
        }
        if (i==n-1)
            break;
            
        v[count].buy = i++;
        
        while((i<n) && (price[i]>=price[i-1])){
            i++;
        }
        
        v[count].sell = i-1;
         count++;
    }
    
    if (count==0){
        cout<<"No Profit";
    }
    else{
        for(int i=0;i<count;i++){
            cout<<"("<<v[i].buy<<" "<<v[i].sell<<")"<<" ";
        }
    }
    return;
}
int main() {
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    int* price = new int[n];
	    for (int i=0;i<n;i++)
	        cin>>price[i];
	    buysell(price,n);
	    cout<<endl;
	}
	return 0;
}
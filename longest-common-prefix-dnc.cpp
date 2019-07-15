//longest common prefix among strings
// geeks gee geks :- ans : ge
//Divide and Conquer (Recursion)
//base case if only 1 strinhg in the array
#include <iostream>
using namespace std;
string commonPrefTwo(string str1,string str2){
    int min_len = (str1.size()<str2.size())?str1.size():str2.size();
    int cp=0;
    for (int i=0;i<min_len;i++){
        if (str1[i] == str2[i])
            cp++;
        else
            break;
    }
    return str1.substr(0,cp);
}
string commonPrefix(string arr[], int low, int high){
    if (low == high)
        return (arr[low]);
        
    if (low < high){
        int mid = low + (high - low)/2;
        
        string str1 = commonPrefix(arr,low,mid);
        string str2 = commonPrefix(arr,mid+1,high);
        
        return (commonPrefTwo(str1,str2));
    }
}
int main() {
	int t;cin>>t;
	while(t--){
	    int n;
	    cin>>n;

	    string arr[n];
	  
	    for (int i=0;i<n;i++){
	        cin>>arr[i];
	    }
        string ans = commonPrefix(arr,0,n-1);
        if (ans=="")
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
	 
	}
	return 0;
}
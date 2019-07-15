int maxLen(int arr[], int n)
{
    for(int i=0;i<n;i++){
        if (arr[i]==0){
            arr[i] = -1;
        }
    }
    unordered_map<int,int> map;
    int maxl = 0;
    int sum = 0;
    for (int i=0;i<n;i++){
        sum += arr[i];
        if (arr[i]==0 && maxl==0)
            maxl = 1;
        if (sum==0)
            maxl = i+1;
        if (map.find(sum)!=map.end())
            maxl = max(maxl,i - map[sum]);
        else
            map[sum] = i;
    }
    return maxl;
}

#include <bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int n);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<maxLen(a,n)<<endl;
		
	}
	return 0;
}

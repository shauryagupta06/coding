#include <iostream>
using namespace std;

int shellSort(int arr[], int n){
    for (int gap = n/2; gap >0; gap /= 2){
        for (int i = gap; i<n ; i++){
            int temp = arr[i];
            
            int j;
            
            for (j = i; j>=gap && arr[j-gap] > temp; j -= gap){
                arr[j] = arr[j-gap]; 
            }
            arr[j] = temp;
        }
    }
    return 0;
}
int main() {
	int arr[] = {3,5,6,2,8};
	shellSort(arr,5);
	for (int i=0;i<5;i++)
	    cout << arr[i]<<" ";
	return 0;
}
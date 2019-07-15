int trappingWater(int arr[], int n){
    int i=0;
    int j=n-1;
    int lmax = 0;
    int rmax = 0;
    int total = 0;
    while (i<=j){
        if (arr[i] < arr[j]){
            if (arr[i] > lmax)
                lmax = arr[i];
            else 
                total += lmax - arr[i];
            i++;
        }
        else{
            if (arr[j] > rmax)
                rmax = arr[j];
            else 
                total += rmax - arr[j];
            j--;
        }
    }
    return total;
}
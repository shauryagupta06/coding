//Kadane algo for max sum subarray
//We'll keep adding elements in currmax

//currmax at index i = max sum ending at i mandatorily
//including arr[i]

//gmax at i = best of all currmax i.e. ans
//ending for arr (0..i) because we may or may not
//include the current arr[i]

//if currmax becomes negative, we should start again from 0
//so that the baggage is left behind

//Here we use dp as in using previous ans to get the new one
//but we do not require a separate array

int kadane(int* arr, int n){
    int currmax = 0;
    int gmax = 0;
    for (int i = 0; i < n; i++){
        currmax = currmax + arr[i];
        if (currmax > gmax){
            gmax = currmax;
        }
        cout << currmax << endl;
        if (currmax < 0){
            currmax = 0;
        }
    }
    return gmax;
}

//same-concept

int kadane(int* arr, int n){
    int currmax = arr[0];
    int gmax = arr[0];
    for (int i = 1; i < n; i++){
        currmax = max(currmax + arr[i], arr[i]);
        cout << currmax << endl;
        gmax = max(gmax, currmax);
    }
    return gmax;
}
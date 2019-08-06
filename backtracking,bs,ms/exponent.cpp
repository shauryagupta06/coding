//Given x and n, return x^n

//A1: pow function of STL : pow(x,n)

//A2: Iterative 1 : p = 1;
//while (n), p *= x
//Time : O(n)

//A2: Recursive 1 : if n = 0, return 1 
//else return x*power(x, n - 1)
//Time: O(n)

//To reduce time , we can have a recursive relation b/w 
//half of n and x

//A3: Recursive 2: Call for x^(n/2) twice
//No of calls: 2^1 + 2^2 + .... + 2^log(n) = 2^(log(n) + 1)
//= 2^log(2n) = 2n , so time : O(n)

#include<iostream>
using namespace std;
int power(int x, int n){
    if (n == 0){
        return 1;
    }
    if (n % 2 == 0){
        return power(x, n/2)*power(x, n/2);
    }
    else{
        return x*power(x, n/2)*power(x, n/2);
    }
}
int main() {
	int x, n;
    cin>>x>>n;
    cout<<power(x, n);
	
}

//A4: Recursive 3: A3 optimized, call fn(x, n/2) once
//No of calls: log(n) , so time: O(logn)

int power(int x, int n){
    if (n == 0){
        return 1;
    }
    int temp = power(x,n/2);
    if (n % 2 == 0){
        return temp*temp;
    }
    else{
        return x*temp*temp;
    }
}
int main() {
	int x, n;
    cin>>x>>n;
    cout<<power(x, n);
	
}
//A5: Recursive 4: x is float, n can be negative also
//Time : O(logn)

int power(int x, int n){
    if (n == 0){
        return 1;
    }
    float temp = power(x,n/2);
    if (n % 2 == 0){
        return temp*temp;
    }
    else{
        if (n > 0)
            return x*temp*temp;
        else
            return (1/x)*temp*temp;
    }
}
//The recursive solutions are generally not preferred as
// they require space on call stack and 
//they involve function call overhead.

//A6: Iterative 2 Time : log(n)
//Dividing n by 2 at each iteration: logn times loop
//At every loop,  if n odd, multiply curr x it to result
//else, do not
//y = y/2
// x = x^2
//Logic : conversion to power to base 2(binary)
//eg. 3^19 = 3^1 * 3^2 * 3^16
//i.e. 19 = 2^0 + 2^1 + 2^4
int power(int x, int n){
    int res = 1;
    while (n > 0){
        if (n%2 == 1){
            res = res*x;
        }
        n = n/2;
        x = x*x;
    }
    return res;
}
int main() {
	int x, n;
    cin>>x>>n;
    cout<<power(x, n);
	
}


